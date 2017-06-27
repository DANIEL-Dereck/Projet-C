/*
** my_printf_ofunction.c for printf in /home/jouana_j/rendu/printf
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Thu Nov 14 09:55:01 2013 jouana_j
** Last update Sat Nov 16 18:15:45 2013 jouana_j
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void	my_printf_car(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

void	my_printf_str(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

void	my_printf_hexaup(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), 16, 1);
}

void	my_printf_size(va_list ap)
{
  my_put_nbr(my_strlen(va_arg(ap, char *)));
}

void	my_printf_dec(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}
