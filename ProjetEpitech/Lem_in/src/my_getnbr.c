/*
** my_getnbr.c for my_getnbr in /home/besnie_b
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Thu Oct  3 20:39:15 2013 besnie_b
** Last update Sun May  4 20:57:36 2014 daniel_d
*/

#include "my.h"
#include "lem_in.h"

int	my_getnbr(char *str)
{
  int	s;
  int	k;
  int	i;

  i = 0;
  k = 1;
  s = signe_func(str);
  k = value_func(str, s, i, k);
  if (s == 1)
    k = -k;
  return (k);
}

int	value_func(char *str, int s, int i, int k)
{
  int	lgt;
  int	pow;

  k = 0;
  pow = 1;
  lgt = my_strlen(str) - 1;
  if (s == 1)
    lgt--;
  while (i++ < lgt)
    pow = pow * 10;
  i = 0;
  while (!(str[i] > 47 && str[i] < 58))
    i++;
  while (str[i] != 0)
    {
      if (str[i] > 47 && str[i] < 58)
	{
	  k = (str[i] - 48) * pow + k;
	  pow = pow / 10;
	}
      i++;
    }
  return (k);
}

int	signe_func(char *str)
{
  int	k;

  k = 0;
  if (str[0] == '-')
    k = 1;
  else
    k = 0;
  return (k);
}
