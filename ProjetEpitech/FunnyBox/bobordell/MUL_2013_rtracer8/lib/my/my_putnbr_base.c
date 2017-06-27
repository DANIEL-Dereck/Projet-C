/*
** my_putnbr_base.c for Piscine-C-Jour_06/ex_15 in /home/jouana_j/rendu/Piscine-C-Jour_06/ex_15
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Wed Oct  9 08:36:45 2013 jouana_j
** Last update Thu Nov 14 18:50:48 2013 jouana_j
*/

#include "my.h"

void	my_put_affichage(int tmp, int *p, int upcase)
{
  if (tmp < 10)
    my_putchar(tmp + 48);
  else
    {
      if (upcase == 1)
	my_putchar(tmp + 55);
      else
	my_putchar(tmp + 87);
    }
  *p = *p - 1;
}

void	my_putnbr_base(int nb, int base, int upcase)
{
  int	i;
  int	p;
  int	tmp;

  p = 0;
  tmp = nb;
  if (nb < 0)
    nb = - nb;
  while (tmp > base)
    {
      tmp = tmp / base;
      p = p + 1;
    }
  while (p >= 0)
    {
      tmp = nb;
      i = 0;
      while (i < p)
	{
	  tmp = tmp / base;
	  i = i + 1;
	}
      tmp = tmp % base;
      my_put_affichage(tmp, &p, upcase);
    }
}
