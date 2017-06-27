/*
** my_putnbr_base_rec.c for rec in /home/daniel_d/Name_Prog/Lib/lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Dec 10 12:52:38 2013 daniel_d
** Last update Wed Feb 19 14:15:07 2014 daniel_d
*/

#include "my.h"

int     my_putnbr_base_rec(int nb, char *base)
{
  int   c;

  c = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= c)
    {
      my_putnbr_base_rec(nb / c, base);
      my_putnbr_base_rec(nb % c, base);
    }
  else
    my_putchar(base[c]);
  return (0);
}
