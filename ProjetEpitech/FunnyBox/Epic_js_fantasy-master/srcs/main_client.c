/*
** main.c for test in /home/js/last_rush/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Sat May 10 04:14:58 2014 thibau_j
** Last update Sat May 10 04:44:39 2014 thibau_j
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "network_client.h"

void		function_read(char *buff, size_t size)
{
  char		tab[1024];
  int		ret;

  printf("%s\n", buff);
  write(1, "client> ", 8);
  if ((ret = read(0, tab, 1024)) == -1)
    exit(EXIT_FAILURE);
  tab[ret] = '\0';
  write_on_server(tab, strlen(tab));
}

int		main()
{
  if (client_init(NULL, 0, function_read) == -1)
    return (-1);
  client_loop();
}
