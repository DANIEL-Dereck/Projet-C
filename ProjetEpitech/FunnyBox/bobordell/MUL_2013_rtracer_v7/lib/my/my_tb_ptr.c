/*
** my_tb_ptr.c for my_printf in /home/jouana_j/rendu/printf
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Thu Nov 14 18:10:59 2013 jouana_j
** Last update Sat Nov 16 18:12:03 2013 jouana_j
*/

#include <stdarg.h>
#include "my_printf_header.h"

void    my_pfunc(void (**my_p)(va_list))
{
  my_p[0] = &my_printf_dec;
  my_p[1] = &my_printf_dec;
  my_p[2] = &my_printf_car;
  my_p[3] = &my_printf_str;
  my_p[4] = &my_printf_hexa;
  my_p[5] = &my_printf_hexaup;
  my_p[6] = &my_printf_point;
  my_p[7] = &my_printf_bin;
  my_p[8] = &my_printf_oct;
  my_p[9] = &my_printf_size;
  my_p[10] = &my_printf_s;
  my_p[11] = &my_printf_u;
  my_p[12] = '\0';
}

void    my_arg_printf(char *symbol)
{
  symbol[0] = 'd';
  symbol[1] = 'i';
  symbol[2] = 'c';
  symbol[3] = 's';
  symbol[4] = 'x';
  symbol[5] = 'X';
  symbol[6] = 'p';
  symbol[7] = 'b';
  symbol[8] = 'o';
  symbol[9] = 'n';
  symbol[10] = 'S';
  symbol[11] = 'u';
  symbol[12] = '\0';
}
