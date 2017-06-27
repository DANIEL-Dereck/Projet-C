/*
** client2.c for rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Server
** 
** Made by decouf_m
** Login   <decouf_m@epitech.net>
** 
** Started on  Sun May 11 03:42:08 2014 decouf_m
** Last update Sun May 11 03:43:04 2014 decouf_m
*/

#include "network_server.h"
#include "misc.h"
#include "server.h"

t_manage	*init_select(t_manage *m)
{
  FD_ZERO(&m->rdfs);
  FD_SET(STDIN_FILENO, &m->rdfs);
  FD_SET(m->s->sock, &m->rdfs);
  m = clear_client(m);
  return (m);
}

t_manage	*read_client(t_manage *m, int i)
{
  t_client	c;
  int	n;
  char		buf[BUFFER_SIZE];

  n = 0;
  c = m->c[i];
  if ((n = recv(c.sock, buf, BUFFER_SIZE - 1, 0)) < 0)
    return (my_perror_ptr("recv()"));
  if (n == 0)
    return (delete_client(m, i));
  else
    {
      buf[n] = '\0';
      my_putstr(buf);
    }
  return (m);
}

t_manage	*select_client(t_manage *m)
{
  int		i;

  i = 0;
  while (i < m->nbr_client)
    {
      if (FD_ISSET(m->c[i].sock, &m->rdfs))
	{
	  m = read_client(m, i);
	}
      i += 1;
    }
  return (m);
}
