/*
** my_putnbr.c for putnbr in /home/daniel_d/colle3-daniel_d/lib
**
** Made by daniel_d
** Login   <daniel_d@epitech.net>
**
** Started on  Thu May 15 19:13:44 2014 daniel_d
** Last update Thu May 15 21:36:32 2014 daniel_d
*/

#include "text.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(nb + '0');
}
