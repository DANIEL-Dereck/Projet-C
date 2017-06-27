/*
** my_put_nbr.c for my_put_nbr in /home/le-fra_g/rendu/Piscine-C-lib/my
** 
** Made by le-fra_g
** Login   <le-fra_g@epitech.net>
** 
** Started on  Wed Oct 30 17:41:03 2013 le-fra_g
** Last update Mon May 19 14:26:16 2014 le-franc
*/

#include "../include/my.h"

int	my_abs(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      return ((nb * (-1)));
    }
  else
    return (nb);
}

int	my_putnbr(int nb)
{
  int	i;
  int	p;
  int	tmp;

  i = 0;
  p = 0;
  nb = my_abs(nb);
  tmp = nb;
  while (tmp >= 10)
    {
      tmp = tmp / 10;
      p++;
    }
  while (p >= 0)
    {
      tmp = nb;
      i = -1;
      while (++i < p)
	tmp = tmp / 10;
      tmp = tmp % 10;
      my_putchar(tmp + 48);
      p--;
    }
  return (0);
}
