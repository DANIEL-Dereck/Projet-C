/*
** client.c for rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Server
** 
** Made by decouf_m
** Login   <decouf_m@epitech.net>
** 
** Started on  Sun May 11 05:36:36 2014 decouf_m
** Last update Sun May 11 03:47:22 2014 decouf_m
*/

#include <string.h>
#include "network_server.h"
#include "misc.h"
#include "server.h"

t_manage	*clear_client(t_manage *m)
{
  int	i;

  i = 0;
  while (i < MAX_CLIENTS)
    {
      FD_SET(m->c[i].sock, &m->rdfs);
      i += 1;
    }
  return (m);
}

t_manage	*add_client(t_manage *m)
{
  t_client	c;
  SOCKET	csock;
  SOCKADDR_IN	csin;

  if ((csock = accept(m->s->sock, (SOCKADDR *)&csin, &m->len)) == SOCKET_ERROR)
    return (my_perror_ptr("accept()"));
  m->max_socket = (csock > m->max_socket) ? (csock) : (m->max_socket);
  my_putstr("Welcom New Client\n");
  c.sock = csock;
  if (m->nbr_client + 1 <= MAX_CLIENTS)
    {
      m->c[m->nbr_client] = c;
      m->nbr_client += 1;
    }
  else
    {
      close(c.sock);
      my_putstr("server is empty\n");
    }
  return (m);
}

t_manage	*delete_client(t_manage *m, int i)
{
  my_putstr("client disconect\n");
  closesocket(m->c[i].sock);
  memmove(m->c + i, m->c + i + 1, (m->nbr_client - i - 1) * sizeof(t_client));
  m->nbr_client -= 1;
  if (m->nbr_client > 0)
    {
      if (i >= 1)
	m->max_socket = m->c[i - 1].sock;
	  else
	    m->max_socket = m->c[i + 1].sock;
    }
  else
    m->max_socket = m->s->sock;
  return (m);
}

