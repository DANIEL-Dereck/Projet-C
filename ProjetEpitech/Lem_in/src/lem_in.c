/*
** lem_in.c for lem_in in /home/besnie_b/Lem_in
**
** Made by besnie_b
** Login   <besnie_b@epitech.net>
**
** Started on  Wed Apr 30 16:53:14 2014 besnie_b
** Last update Sun May  4 22:28:53 2014 besnie_b
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lem_in.h"

int	us_lem_in(char **tab)
{
  t_node *node;

  node = my_node_tab(tab);
  node = my_info_in_node(tab, node);
  node = prepared_pipes(node);
  my_pipe_conf(tab);
  return (0);
}

int	main()
{
  char	buffer[2049];

  clear_buffer(buffer);
  if ((read(0, buffer, 2049)) == -1)
    return (0);
  lem_in_func(buffer);
  return (0);
}
