/*
** main.c for minishell in /home/daniel_d/rendu/PSU_2013_minishell2/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Mar  9 23:33:04 2014 daniel_d
** Last update Sun Mar  9 23:33:05 2014 daniel_d
*/

#include <stdio.h>
#include "my.h"
#include "my_minishell.h"

int main(int ac, char **av, char **envp)
{
  if (envp[0] == NULL)
    {
      my_printf("ERROR : no environement\n");
      return (0);
    }
  if (ac != 1)
    {
      my_printf("ERROR : too many arguments\n");
      my_printf("Usage : %s\n", av[0]);
      return (0);
    }
  my_prompt(envp);
  return (0);
}
