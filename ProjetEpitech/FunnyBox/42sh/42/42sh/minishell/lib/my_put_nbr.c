/*
** my_put_nbr.c for int my_put_nbr(int nb) in /home/boucha_q/rendu/Piscine-C-Jour_03
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Wed Oct  2 19:48:04 2013 boucha_q
** Last update Mon Apr 14 13:53:21 2014 bouchard alexandre
*/

#include "my.h"

void	my_put()
{
  my_putchar('-');
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
}

int	my_put_nbr(int nb)
{
  int	p;
  int	np;

  p = 1;
  if (nb < 0 )
    {
      nb = nb * - 1;
      my_putchar('-');
      my_putchar(nb);
    }
  while (nb / p > 9)
    {
      p = p * 10;
    }
  while (p > 0)
    {
      np = nb / p;
      p = p / 10;
      np = np % 10;
      my_putchar(np + 48);
    }
  return (0);
}
