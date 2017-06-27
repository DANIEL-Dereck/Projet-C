/*
** my_strlen.c for my_strlen.c in /home/le-fra_g/minishel
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Fri May 16 16:54:28 2014 le-franc
** Last update Fri May 16 17:08:23 2014 le-franc
*/

#include "../include/my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i = i + 1;
  return (i);
}
