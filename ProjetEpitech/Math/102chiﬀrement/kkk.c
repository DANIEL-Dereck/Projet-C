/*
** kkk.c for kkk in /home/auffra_a/rendu/BORDOULE
** 
** Made by auffra_a
** Login   <auffra_a@epitech.net>
** 
** Started on  Tue Dec  3 16:21:04 2013 auffra_a
** Last update Wed Dec  4 17:10:50 2013 daniel_d
*/

#include "Lib/include/my.h"

int	chiffrement(int *tab, int *key, int len, char *base)
{
  int i;

  i = 0;
  while (i <= len)
    {
      my_putnbr_base((tab[i] * key[0] + tab[i+1] * key[2]), base);
      my_putchar(' ');
      my_putnbr_base((tab[i] * key[1] + tab[i+1] * key[3]), base);
      my_putchar(' ');
      i = i + 2;
    }
  my_putchar('\n');
}
