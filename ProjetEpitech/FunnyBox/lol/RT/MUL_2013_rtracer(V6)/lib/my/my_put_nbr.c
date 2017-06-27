/*
** my_put_nbr.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:34:31 2013 jouana_j
** Last update Thu Nov 14 17:24:12 2013 jouana_j
*/

#include "my.h"

int	my_abs(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      return (-nb);
    }
  else
    return (nb);
}

void	my_put_nbr(int nb)
{
  int	i;
  int	p;
  int	tmp;

  p = 0;
  nb = my_abs(nb);
  tmp = nb;
  while (tmp >= 10)
    {
      tmp = tmp / 10;
      p = p + 1;
    }
  while (p >= 0)
    {
      tmp = nb;
      i = 0;
      while (i < p)
	{
	  tmp = tmp / 10;
	  i = i + 1;
	}
      tmp = tmp % 10;
      my_putchar(tmp + 48);
      p = p - 1;
    }
}
