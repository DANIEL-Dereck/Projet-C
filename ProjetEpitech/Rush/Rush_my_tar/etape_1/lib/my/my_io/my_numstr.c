/*
** my_numstr.c for libmy in /home/bertho_d/rendu/lib/my
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Thu Nov 21 10:05:39 2013 bertho_d
** Last update Thu Nov 21 11:06:24 2013 bertho_d
*/

#include "my.h"

int	get_numstr_sign(char *str, int *nb_signs)
{
  int	sign;

  *nb_signs = 0;
  sign = 1;
  while (str[*nb_signs] == '+' || str[*nb_signs] == '-')
    {
      if (str[*nb_signs] == '-')
	sign = -sign;
      *nb_signs += 1;
    }
  return (sign);
}

int	check_numstr(char *str, char *base)
{
  int	i;

  if (!str || !base)
    return (-1);
  i = 0;
  while (str[i] != '\0')
    {
      if (my_find_char(str[i], base) == -1)
	return (-1);
      i += 1;
    }
  return (i);
}

int	my_check_base(char *base, char *forbidden_chars)
{
  int	base_type;

  base_type = 0;
  while (base[base_type] != '\0')
    {
      if (my_find_char(base[base_type], forbidden_chars) >= 0 ||
	  my_find_char(base[base_type], &base[base_type + 1]) >= 0)
	return (0);
      base_type += 1;
    }
  return (base_type);
}
