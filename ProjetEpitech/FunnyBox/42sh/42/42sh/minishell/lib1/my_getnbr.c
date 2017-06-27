/*
** my_getnbr.c for my_getnbr in /home/le-fra_g/rendu/Piscine-C-lib/lib
** 
** Made by le-fra_g
** Login   <le-fra_g@epitech.net>
** 
** Started on  Mon Oct 21 09:26:26 2013 le-fra_g
** Last update Mon May 19 14:23:23 2014 le-franc
*/

#include "../include/my.h"

int	nbrlen(char *str)
{
  int	 a;

  a = 0;
  while (str[a]  != '\0')
    a++;
  return (a);
}

int	my_pow(int a)
{
  int	m;
  int	p;

  m = 1;
  p = 1;
  while (m < a)
    {
      p = p * 10;
      m = m + 1;
    }
  return (p);
}

int	my_getnbr(char *str)
{
  int	b;
  int	pow;
  int	a;
  int	res;

  b = nbrlen(str);
  pow = my_pow(b);
  a = 0;
  if (str[a] == '-')
    {
      b = -1;
      a = a + 1;
    }
  while (str[a] != '\0')
    {
      res = res + (str[a] - 48) * pow;
      a = a + 1;
      pow = pow / 10;
    }
  my_putnbr(res);
  return (res);
}
