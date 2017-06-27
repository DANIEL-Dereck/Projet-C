/*
** my_strncmp.c for my_strncmp.c in /home/le-fra_g/minishel/lib
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Fri May 16 17:28:00 2014 le-franc
** Last update Fri May 16 17:28:34 2014 le-franc
*/

#include "../include/my.h"

int     my_strncmp(char *str, char *str2, int a)
{
  int   i;
  int   n;

  i = 0;
  while (i < a)
    {
      if (str2[i] == str[i])
        n = 1;
      else
        n = 0;
      i++;
    }
  return (n);
}
