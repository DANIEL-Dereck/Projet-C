/*
** my_io.c for libmy in /home/bertho_d/rendu/lib/io
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Oct 12 17:54:36 2013 bertho_d
** Last update Thu Nov 21 08:33:58 2013 bertho_d
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	len;

  if ((len = my_strlen(str)) < 1)
    return ;
  write(1, str, len);
}

void	my_put_n_chars(char c, int n)
{
  while (n > 0)
    {
      my_putchar(c);
      n -= 1;
    }
}

void	my_showstr_n_base(char *str, int len, char *base)
{
  int	i;
  int	base_type;
  int	nb_len;

  if (!str || !base)
    return ;
  i = 0;
  base_type = my_strlen(base);
  nb_len = calc_u_nb_len((1 << 8) - 1, base_type);
  while (str[i] && (i < len || len < 0))
    {
      if (!my_char_type(str[i]))
	{
	  my_putchar('\\');
	  my_put_n_chars(base[0], nb_len - calc_u_nb_len(str[i], base_type));
	  my_ulong_putnbr_base(str[i], base);
	}
      else
	my_putchar(str[i]);
      i += 1;
    }
}

void	my_showstr(char *str)
{
  my_showstr_n_base(str, -1, "0123456789abcdef");
}
