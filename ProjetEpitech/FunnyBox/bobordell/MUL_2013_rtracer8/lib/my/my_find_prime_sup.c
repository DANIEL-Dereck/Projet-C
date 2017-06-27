/*
** my_find_prime_sup.c for Piscine-C-lib/my in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Tue Oct  8 08:41:07 2013 jouana_j
** Last update Thu Nov 14 17:32:57 2013 jouana_j
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (n == 0)
    {
      n = my_is_prime(nb + i);
      i = i + 1;
    }
  return (n);
}
