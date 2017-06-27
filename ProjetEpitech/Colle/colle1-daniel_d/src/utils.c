/*
** utils.c for colle1 in /home/thepatriot/rendu/colle1
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Tue Apr 29 15:02:11 2014 bertho_d
** Last update Tue Apr 29 17:54:27 2014 bertho_d
*/

#include <stdlib.h>
#include "pi.h"

void		my_memset(char *ptr, char val, int size)
{
  while (--size >= 0)
    ptr[size] = val;
}

int		my_strlen(char *str)
{
  int		len;

  len = -1;
  if (str)
    while (str[++len]);
  return (len);
}

int		my_atoi(char *str)
{
  unsigned int	max_val;
  unsigned int	mul;
  unsigned int	res;
  char		*start;
  char		*ptr;

  start = str;
  while (*str >= '0' && *str <= '9')
    str += 1;
  max_val = (~0) >> 1;
  ptr = str;
  res = 0;
  mul = 1;
  while (--ptr >= start)
    {
      if (((*ptr - '0') && mul > (max_val - res) / (*ptr - '0')) ||
	  ((mul != 1) && (mul % 10)))
	return (-1);
      res += (*ptr - '0') * mul;
      mul *= 10;
    }
  return (res);
}
