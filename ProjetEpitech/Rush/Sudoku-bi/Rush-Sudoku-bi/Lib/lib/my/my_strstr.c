/*
** my_strstr.c for my_strstr.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct  7 16:36:35 2013 daniel_d
** Last update Wed Feb 19 13:46:37 2014 daniel_d
*/

#include "my.h"

int	my_put_strstr(char *str, char *to_find)
{
  int h;

  h = 0;
  while (str[h++] != *to_find);
  if (str[h] == *to_find)
    {
      while (str[h] != '\0')
	{
	  my_putchar(str[h]);
	  h = h + 1;
	}
    }
  return (h);
}

char	*my_strstr(char *str, char *to_find)
{
  my_put_strstr(str, to_find);
  return (str);
}
