/*
** my_getnbr.c for libmy in /home/bertho_d/rendu/lib/io
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Oct 12 17:54:12 2013 bertho_d
** Last update Fri Nov 22 01:45:16 2013 bertho_d
*/

#include "my.h"
#include "my_defines.h"

static int	getnbr_base_rec(char *str, char *base, int length, int sign)
{
  int	nb;
  int	power;
  int	result;
  int	base_type;

  base_type = my_strlen(base);
  if (length < 1)
    return (0);
  length -= 1;
  result = getnbr_base_rec(&str[1], base, length, sign);
  if (result == -1)
    return (-1);
  nb = my_find_char(str[0], base);
  if (nb == 0)
    return (result);
  power = my_pow(base_type, length);
  if (power == 0 || -power < (((1 << (8 * sizeof(int) - 1))
			       + 1 - sign + result) / nb))
    return (-1);
  return (nb * power + result);
}

static int	getnbr_rec(char *str, int len, int sign)
{
  int	result;
  int	power;

  if (len < 1)
    return (0);
  len -= 1;
  result = getnbr_rec(&str[1], len, sign);
  if (result == -1)
    return (-1);
  if (str[0] == '0')
    return (result);
  power = my_pow(10, len);
  if (power == 0 || -power < (((1 << (8 * sizeof(int) - 1))
			      + 1 - sign + result) / (str[0] - '0')))
    return (-1);
  return ((str[0] - '0') * power + result);
}

int	my_getnbr_base(char *str, char *base)
{
  int	sign;
  int	pos;
  int	base_type;
  int	result;

  if (!str || !base)
    return (0);
  base_type = my_check_base(base, "");
  if (base_type == 0)
    return (0);
  sign = get_numstr_sign(str, &pos);
  str = &str[pos];
  pos = check_numstr(str, base);
  if (pos < 1)
    return (0);
  if (base_type == 1)
    return (sign * pos);
  result = getnbr_base_rec(str, base, pos, (sign < 0));
  if (result == -1)
    return (0);
  return (sign * result);
}

int	my_getnbr(char *str)
{
  int	result;
  int	sign;
  int	len;
  int	i;

  if (!str)
    return (0);
  len = 0;
  sign = get_numstr_sign(str, &i);
  while (str[i] == '0')
    i += 1;
  while (my_char_type(str[i + len]) == MY_NUMERIC_CHAR)
    len += 1;
  result = getnbr_rec(&str[i], len, (sign < 0));
  if (result == -1)
    return (0);
  return (sign * result);
}

int	my_atoi(char *str)
{
  return (my_getnbr(str));
}
