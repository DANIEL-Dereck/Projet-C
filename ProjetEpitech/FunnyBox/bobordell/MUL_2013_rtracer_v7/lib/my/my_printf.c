/*
** my_printf.c for printf in /home/jouana_j/rendu/printf
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Tue Nov  5 16:27:02 2013 jouana_j
** Last update Sun Dec  8 11:34:12 2013 jouana_j
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf_header.h"

void	my_printf_except(const char *format, char *symbol, int *i, int j)
{
  if (format[*i] == '%' && symbol[j] == '\0')
    {
      my_putchar(format[*i]);
    }
}

void	my_printf_verif(const char *format, va_list ap, char *symbol,
			void (**my_p)(va_list))
{
  int	i;
  int	j;

  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  j = 0;
	  while (symbol[j] != '\0')
	    {
	      if (format[i + 1] == symbol[j])
		{
		  my_p[j](ap);
		  i = i + 1;
		}
	      j = j + 1;
	    }
	  }
      else
	my_putchar(format[i]);
      my_printf_except(format, symbol, &i, j);
      i = i + 1;
    }
}

void	my_printf(const char *format, ...)
{
  va_list ap;
  char	*symbol;
  void	(*my_p[13])(va_list);

  symbol = malloc(sizeof(*symbol) * 13);
  my_arg_printf(symbol);
  my_pfunc(my_p);
  va_start(ap, format);
  my_printf_verif(format, ap, symbol, my_p);
  va_end(ap);
}
