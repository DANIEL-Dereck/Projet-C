/*
** my_strlen.c for my_strlen.c in /home/daniel_d/rendu/Piscine-C-Jour_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  9 09:56:02 2013 daniel_d
** Last update Fri Jun  6 17:43:49 2014 daniel_d
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int a;

  a = 0;
  if (str == NULL)
    return (-1);
  while (str[a++] != '\0');
  a--;
  return (a);
}
