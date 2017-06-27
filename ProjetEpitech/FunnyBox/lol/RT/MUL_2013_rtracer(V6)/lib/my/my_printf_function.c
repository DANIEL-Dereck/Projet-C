/*
** my_printf_function.c for printf in /home/jouana_j/rendu/printf
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Thu Nov 14 09:38:11 2013 jouana_j
** Last update Sat Nov 16 18:12:29 2013 jouana_j
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void	my_printf_hexa(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), 16, 0);
}

void	my_printf_point(va_list ap)
{
  my_putchar('0');
  my_putchar('x');
  my_putnbr_base_long(va_arg(ap, long), 16, 0);
}

void	my_printf_bin(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), 2, 0);
}

void	my_printf_oct(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), 8, 0);
}
