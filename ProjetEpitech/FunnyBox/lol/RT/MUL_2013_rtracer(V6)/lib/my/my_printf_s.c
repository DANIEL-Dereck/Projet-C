/*
** my_printf_s.c for my_printf in /home/jouana_j/rendu/printf
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Thu Nov 14 13:49:17 2013 jouana_j
** Last update Sat Nov 16 17:47:46 2013 jouana_j
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

void	my_printf_s(va_list ap)
{
  int	i;
  char	*str;

  str = va_arg(ap, char *);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 32 && str[i] < 127)
	my_putchar(str[i]);
      else
	{
	  my_putchar(92);
	  if (str[i] < 8)
	    my_putstr("00");
	  else if (str[i] >= 8 && str[i] < 64)
	    my_putchar('0');
	  my_putnbr_base(str[i], 8, 0);
	}
      i = i + 1;
    }
}

void	my_printf_u(va_list ap)
{
  my_putnbr_u_rec(va_arg(ap, unsigned int));
}
