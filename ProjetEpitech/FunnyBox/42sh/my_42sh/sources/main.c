/*
** main.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/my_read/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Thu Apr 24 14:09:45 2014 bouchard alexandre
** Last update Sun May 25 23:09:16 2014 dumlup_i
*/

#include "../include/sh.h"

int	main(int ac, char **av, char **env)
{
  t_list	*list_env;
  int	i;

  (void)ac;
  (void)av;
  i = 0;
  my_tmp_alias();
  list_env = NULL;
  if (env != NULL)
    {
      list_env = my_env_in_list(list_env, env);
      i = my_42sh(list_env);
    }
  else
    printf("no env\n");
  return (i);
}
