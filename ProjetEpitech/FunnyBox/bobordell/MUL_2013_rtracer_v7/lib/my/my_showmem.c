/*
** my_showmem.c for Piscine-C-lib/my in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Tue Oct  8 09:11:57 2013 jouana_j
** Last update Thu Nov 14 17:53:40 2013 jouana_j
*/

#include "my.h"

void	my_hexa(char c)
{
  int	i;
  int	p;
  int	tmp;

  p = 0;
  tmp = c;
  while (tmp >= 16)
    {
      tmp = tmp / 16;
      p = p + 1;
    }
  while (p >= 0)
    {
      tmp = c;
      i = 0;
      while (i < p)
	{
	  tmp = tmp / 16;
	  i = i + 1;
	}
      tmp = tmp % 16;
      my_putchar(tmp + 48);
      p = p - 1;
    }
}

int	my_hexa_str(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_hexa(str[i]);
      i = i + 1;
      if ((i % 2) == 0)
	my_putchar(' ');
    }
  return (0);
}

int	my_showmem(char *str)
{
  my_getnbr(str);
  my_putchar(' ');
  my_hexa_str(str);
  my_putchar(' ');
  my_putstr(str);
  return (0);
}
