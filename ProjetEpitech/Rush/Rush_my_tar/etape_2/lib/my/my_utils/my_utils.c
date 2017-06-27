/*
** utility.c for libmy in /home/bertho_d/rendu/lib
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Oct 12 17:58:17 2013 bertho_d
** Last update Fri Nov 22 01:45:55 2013 bertho_d
*/

#include "my.h"
#include "my_defines.h"

int	my_char_type(char c)
{
  if (c >= 'a' && c <= 'z')
    return (MY_LOWER_CHAR);
  if (c >= 'A' && c <= 'Z')
    return (MY_UPPER_CHAR);
  if (c >= '0' && c <= '9')
    return (MY_NUMERIC_CHAR);
  if (c >= ' ' && c <= '~')
    return (MY_PRINTABLE_CHAR);
  return (0);
}

int	my_find_char(char c, char *str)
{
  int	i;

  i = 0;
  if (str)
    while (str[i])
      {
	if (str[i] == c)
	  return (i);
	i += 1;
      }
  return (-1);
}

char	*next_non_num_char(char *str)
{
  if (str)
    while (my_char_type(*str) == MY_NUMERIC_CHAR || *str == '-')
      str++;
  return (str);
}

void	my_memset(char *address, char value, int len)
{
  if (address)
    while (len > 0)
      {
	len -= 1;
	address[len] = value;
      }
}

int	calc_u_nb_len(unsigned long nb, int base_type)
{
  int	len;

  len = 0;
  while (nb != 0)
    {
      nb /= base_type;
      len += 1;
    }
  return (len);
}
