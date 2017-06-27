/*
** my_cd.c for minishell in /home/daniel_d/rendu/minishell1_re/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Jan 29 09:55:26 2014 daniel_d
** Last update Mon Apr 21 15:01:28 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_minishell.h"

int	my_cd(char *buffer)
{
  int	i;
  int	l;
  char	*str;

  l = 3;
  i = 0;
  if ((str = malloc(sizeof(str) * my_strlen(buffer))) == NULL)
    return (0);
  if (my_strcmp("..\n", buffer) == 2)
    l = 0;
  while (buffer[l] != '\n')
    {
      str[i] = buffer[l];
      i++;
      l++;
    }
  str[i] = '\0';
  if (chdir(str) != 0)
    my_printf("ERROR : %s not a directory\n", str);
  free(str);
  return (0);
}
