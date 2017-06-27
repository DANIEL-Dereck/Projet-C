/*
** 42sh.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/my_42sh/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Fri May 16 15:39:11 2014 bouchard alexandre
** Last update Sun May 25 22:10:57 2014 daniel_d
*/

#include "../include/sh.h"
#include "../include/my.h"

int	my_42sh(t_list *list_env)
{
  char  *buff;
  int	error;
  int	exit;

  signal_set();
  my_putstr("&>");
  while ((buff = my_read()) != NULL)
    {
      exit = -1;
      list_env = my_parse(buff, list_env);
      (void)error;
      if (exit >= 0)
	return (exit);
      my_putstr("&>");
      free(buff);
    }
  my_putstr("exit\n");
  free(buff);
  return (0);
}
