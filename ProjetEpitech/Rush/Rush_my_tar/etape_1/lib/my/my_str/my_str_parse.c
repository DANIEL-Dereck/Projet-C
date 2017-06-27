/*
** my_str_parsing.c for libmy in /home/bertho_d/rendu/my_printf
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sun Nov 10 18:39:05 2013 bertho_d
** Last update Sun Nov 10 19:13:40 2013 bertho_d
*/

#include "my.h"

int	read_positive_int(const char *str, int *nb, int non_zero)
{
  int	len;
  int	i;

  *nb = 0;
  if (*str == '0' && non_zero)
    return (0);
  len = 0;
  while (str[len] >= '0' && str[len] <= '9')
    len += 1;
  i = 0;
  while (i < len)
    {
      *nb += (str[i] - '0') * my_pow(10, len - i - 1);
      i += 1;
    }
  return (i);
}
