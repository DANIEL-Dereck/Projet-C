/*
** js_server.c for rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Server
**
** Made by decouf_m
** Login   <decouf_m@epitech.net>
**
** Started on  Sat May 10 14:57:09 2014 decouf_m
** Last update Sun May 11 03:46:29 2014 decouf_m
*/

#include <string.h>
#include "network_server.h"
#include "misc.h"
#include "server.h"

t_server	*init_server()
{
  t_server	*server;

  if ((server = malloc(sizeof(*server))) == NULL)
    return (NULL);
  if ((server->sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKE)
    return (my_put_error_ptr("[Server] - socket() has failed\n"));
  server->sin.sin_addr.s_addr = htonl(INADDR_ANY);
  server->sin.sin_family = AF_INET;
  server->sin.sin_port = htons(PORT);
  if (bind(server->sock, (SOCKADDR*)&server->sin,
	   sizeof(server->sin)) == SOCKET_ERROR)
    return (my_put_error_ptr("[Server] - bind() has failed\n"));
  listen(server->sock, 5);
  return (server);
}

t_manage	*init_manager()
{
  t_manage	*m;
  SOCKADDR_IN	csin;

  if ((m = malloc(sizeof(*m))) == NULL)
    return (my_perror_ptr("malloc()"));
  m->nbr_client = 0;
  m->len = sizeof(csin);
  if ((m->s = init_server()) == NULL)
    return (0);
  m->max_socket = m->s->sock;
  return (m);
}

t_manage	*server_life(t_manage *m)
{

  while (1)
    {
      m = init_select(m);
      if (select(m->max_socket + 1, &m->rdfs, NULL, NULL, NULL) == -1)
	return (my_perror_ptr("select()"));
      if (FD_ISSET(m->s->sock, &m->rdfs))
	{
	  if ((m = add_client(m)) == NULL)
	    return (0);
	}
      else
	m = select_client(m);
    }
  return (m);
}

int	main()
{
  t_manage	*m;

  if ((m = init_manager()) == NULL)
    return (0);
  if ((m = server_life(m)) == NULL)
    return (0);
  if (closesocket(m->s->sock) < 0)
    return (my_putstr("Closesocket aborted\n"));
  return (1);
}
