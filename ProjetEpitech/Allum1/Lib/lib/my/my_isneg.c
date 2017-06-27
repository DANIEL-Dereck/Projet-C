/*
** my_isneg.c for my_isneg.c in /home/daniel_d/rendu/Piscine-C-Jour_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  2 11:55:13 2013 daniel_d
** Last update Tue Feb 18 15:42:37 2014 daniel_d
*/

#include "my.h"

void	my_isneg(int n)
{
  if (n >= 0)
    my_putchar('p');
  else
    my_putchar('N');
}
