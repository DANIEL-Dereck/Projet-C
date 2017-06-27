/*
** my_putstr.c for putstr in /home/daniel_d/colle3-daniel_d/lib
**
** Made by daniel_d
** Login   <daniel_d@epitech.net>
**
** Started on  Thu May 15 19:11:18 2014 daniel_d
** Last update Thu May 15 19:50:42 2014 even_d
*/

#include <unistd.h>

#include "text.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      my_putchar(str[i++]);
}
