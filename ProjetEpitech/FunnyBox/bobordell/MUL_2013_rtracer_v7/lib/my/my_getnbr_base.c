/*
** my_getnbr_base.c for Piscine-C-Jour_06/ex_16 in /home/jouana_j/rendu/Piscine-C-Jour_06
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Wed Oct  9 09:48:28 2013 jouana_j
** Last update Sun Dec  8 11:30:19 2013 jouana_j
*/

#include "my.h"

int	my_abs_base(int nb)
{
  if (nb < 0)
    return (-nb);
  else
    return (nb);
}

int	calc_getnb_base(char *str, int size)
{
  int	i;
  int	nb;
  int	tmp;
  int	z;

  i = 0;
  nb = 0;
  z = 0;
  while (str[i] != '\0')
    {
      tmp = size;
      z = str[i] - 48;
      while (tmp > 0)
	{
	  z = z * 10;
	  tmp = tmp - 1;
	}
      size = size - 1;
      nb = nb + z;
      i = i + 1;
    }
  return (nb);
}

int	my_getnbase(char *str, int base, int size, int i)
{
  int	p;
  int	tmp;

  p = 0;
  tmp = calc_getnb_base(str, size);
  while (tmp >= base)
    {
      tmp = tmp / base;
      p = p + 1;
    }
  while (p >= 0)
    {
      tmp = calc_getnb_base(str, size);
      i = 0;
      while (i < p)
	{
	  tmp = tmp / base;
	  i = i + 1;
	}
    }
  return (tmp);
}

int	my_getnbr_base(char *str, int base)
{
  int	size;
  int	i;
  int	nb;

  size = 0;
  i = 0;
  while (str[size] != '\0')
    {
      size = size + 1;
    }
  size = size - 1;
  nb = my_getnbase(str, base, size, i);
  return (nb);
}
