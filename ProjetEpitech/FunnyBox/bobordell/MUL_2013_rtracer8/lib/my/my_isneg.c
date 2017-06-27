/*
** my_isneg.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:33:15 2013 jouana_j
** Last update Thu Nov 14 17:33:57 2013 jouana_j
*/

#include "my.h"

void	my_isneg(int n)
{
  if (n < 0)
      my_putchar('N');
  else
      my_putchar('P');
  my_putchar('\n');
}
