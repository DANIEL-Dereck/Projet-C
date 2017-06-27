/*
** main.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/my_read/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Thu Apr 24 14:09:45 2014 bouchard alexandre
** Last update Sat May 17 11:11:24 2014 bouchard alexandre
*/

#include "../include/proto.h"

int	main(int ac, char **av, char **env)
{
  (void)ac;
  (void)av;
  my_tmp_alias();
  if (env != NULL)
    my_42sh(env);
  else
    puts("no env");
  return (0);
}
