/*
** my_putstr.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:35:04 2013 jouana_j
** Last update Sat Nov 16 18:23:25 2013 jouana_j
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
