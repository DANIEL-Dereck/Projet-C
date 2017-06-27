/*
** my_printf_header.h for my_printf in /home/jouana_j/rendu/printf
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Thu Nov 14 10:38:28 2013 jouana_j
** Last update Sat Nov 16 18:09:34 2013 jouana_j
*/

#ifndef PRINTF_H_
#define PRINTF_H_

void my_printf_car(va_list ap);
void my_printf_str(va_list ap);
void my_printf_dec(va_list ap);
void my_printf_hexa(va_list ap);
void my_printf_hexaup(va_list ap);
void my_printf_size(va_list ap);
void my_printf_ld(va_list ap);
void my_printf_point(va_list ap);
void my_printf_bin(va_list ap);
void my_printf_oct(va_list ap);
void my_printf_s(va_list ap);
void my_pfunc(void (**my_p)(va_list));
void my_arg_printf(char *symbol);
void my_printf_u(va_list ap);

#endif
