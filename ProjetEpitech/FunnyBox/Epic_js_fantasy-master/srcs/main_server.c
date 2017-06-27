/*
** main_sercer.c for server.c in /home/js/last_rush/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Sat May 10 04:27:04 2014 thibau_j
** Last update Sat May 10 05:17:34 2014 thibau_j
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "network_server.h"

void		function_read(char *buff, size_t size, int id)
{
  char		tab[1024];
  int		ret;

  printf("%s\n", buff);
  write(1, "server> ", 8);
  if ((ret = read(0, tab, 1024)) == -1)
    exit(EXIT_FAILURE);
  tab[ret] = '\0';
  write_on_client(tab, strlen(tab), id);
  /* close_server(); */
}

int	main()
{
  server_loop(0, &function_read);
}
