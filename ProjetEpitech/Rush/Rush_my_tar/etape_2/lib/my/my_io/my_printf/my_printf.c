/*
** my_printf.c for my_printf in /home/bertho_d/rendu/Piscine-C-lib/my/my_io/my_printf
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sun Nov 10 18:47:55 2013 bertho_d
** Last update Fri Nov 22 01:45:36 2013 bertho_d
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_defines.h"
#include "my_printf.h"

static int	args_loop_mod(const char *format, int *i, int *nb, int *max)
{
  int	temp;

  temp = 0;
  *i += get_target(&format[*i], &temp);
  if (temp)
    *i -= 1;
  *max = MAX(*max, temp);
  if (format[*i] == '*')
    *nb += 1;
  else if (format[*i] == '$')
    *nb -= 1;
  else if (my_find_char(format[*i], CONV_SPECIFIERS) != -1)
    {
      *nb += 1;
      return (0);
    }
  return (1);
}

static int	count_args(const char *format)
{
  int	i;
  int	nb;
  int	mod;
  int	max;

  nb = 0;
  mod = 0;
  max = 0;
  i = 0;
  while (format[i])
    {
      if (mod)
	mod = args_loop_mod(format, &i, &nb, &max);
      else if (format[i] == '%' && format[i + 1] == '%')
	i += 1;
      else if (format[i] == '%')
	mod = 1;
      i += 1;
    }
  return (MAX(nb, max));
}

static int	format_parsing(const char *format, t_args *args)
{
  int	i;
  int	len;
  int	ret_val;

  i = 0;
  len = 0;
  while (format[i])
    {
      if (format[i] == '%')
	{
	  if ((ret_val = get_conv_params(&format[i + 1], args, &len)) < 0)
	    return (-1);
	  else
	    i += ret_val;
	}
      else
	{
	  my_putchar(format[i]);
	  len += 1;
	}
      i += 1;
    }
  return (len);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  t_args	*args;
  int		i;

  if (!format || !(args = malloc(sizeof(*args))))
    return (-1);
  va_start(ap, format);
  args->nb_args = count_args(format);
  if (args->nb_args > 0)
    if (!(args->args = malloc(args->nb_args * sizeof(long int))))
      return (-1);
  i = 0;
  while (i < args->nb_args)
    {
      args->args[i] = va_arg(ap, long);
      i += 1;
    }
  va_end(ap);
  args->actual_arg = 0;
  i = format_parsing(format, args);
  if (args->nb_args > 0)
    free(args->args);
  free(args);
  return (i);
}
