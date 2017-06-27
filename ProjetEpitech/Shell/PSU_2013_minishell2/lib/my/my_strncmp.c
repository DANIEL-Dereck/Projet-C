/*
** my_strncmp.c for relib in /home/daniel_d/rendu/PSU_2013_minishell2/lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Mar  3 16:46:14 2014 daniel_d
** Last update Tue Mar  4 10:46:16 2014 daniel_d
*/

#include <stdio.h>
#include "my.h"

int     my_strncmp(char *s1, char *s2, int nb)
{
  int b;

  if (s1 == NULL || s2 == NULL)
    return (1);
  while (s1[b] != '\0' || nb == 0)
    {
      if (s1[b] != s2[b])
        return (1);
      b++;
      nb--;
    }
  return (2);
}
