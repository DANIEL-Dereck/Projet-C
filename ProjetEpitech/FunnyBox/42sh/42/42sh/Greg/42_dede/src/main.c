/*
** main.c for 42sh in /home/daniel_d/rendu/42/42sh/Dede/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon May 12 15:50:50 2014 daniel_d
** Last update Thu May 15 14:26:20 2014 le-franc
*/

#include "mysh.h"

void	usage(char *sh)
{
  my_printf("Usage : %s [option]\n", sh);
  my_printf("options :\n\t--help\n");
}

int	shmain(char **env)
{
  return (my_prompt(env));
}

int	main(int ac, char **av, char **env)
{
  if (env[0] == NULL)
    {
      my_printf("ERROR : no environement\n");
      return (-1);
    }
  if (ac > 1 && my_strcmp("--help", av[1]) == 0)
    usage(av[0]);
  else
    return (shmain(env));
  return (0);
}
