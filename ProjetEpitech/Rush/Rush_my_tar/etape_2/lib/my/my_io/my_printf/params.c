/*
** params.c for my_printf in /home/bertho_d/rendu/Piscine-C-lib/my/my_io/my_printf
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sun Nov 10 18:49:47 2013 bertho_d
** Last update Thu Nov 21 11:08:03 2013 bertho_d
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static int	get_flags(const char *format, t_params *params)
{
  int	i;
  char	*flags_list;
  char	flag;

  flags_list = "#0- +";
  i = 0;
  while (i < 5)
    {
      flag = my_find_char(format[i], flags_list);
      if (flag == -1)
	return (i);
      else
	{
	  flag = (1 << flag);
	  if (!(params->flags & flag))
	    params->flags += flag;
	  else
	    return (i);
	}
      i += 1;
    }
  return (i);
}

static int	get_min_width(const char *format, t_params *params, t_args *args)
{
  int	i;
  int	target;

  i = 0;
  if (*format == '*')
    {
      i += get_target(format + 1, &target) + 1;
      params->min_width = ((target) ? args->args[target - 1]
			   : args->args[(args->actual_arg)++]);
      return (i);
    }
  i += read_positive_int(format, &(params->min_width), 0);
  return (i);
}

static int	get_precision(const char *format, t_params *params, t_args *args)
{
  int	i;
  int	target;

  if (*format != '.')
    return (0);
  i = 1;
  if (format[i] == '*')
    {
      i += get_target(format + 2, &target) + 1;
      params->precision = ((target) ? args->args[target - 1]
			   : args->args[(args->actual_arg)++]);
      return (i);
    }
  i += read_positive_int((format + 1), &(params->precision), 0);
  return (i);
}

int	get_target(const char *format, int *target)
{
  int	i;

  if (!format || !target)
    return (0);
  i = read_positive_int(format, target, 1);
  if (format[i] == '$')
    return (i + 1);
  *target = 0;
  return (0);
}

int		get_conv_params(const char *format, t_args *args, int *len)
{
  int		i;
  t_params	params;

  params.flags = 0;
  params.min_width = 0;
  params.precision = -1;
  i = get_target(format, &(params.target));
  i += get_flags(&(format[i]), &params);
  i += get_min_width(&(format[i]), &params, args);
  if (params.min_width < 0)
    {
      params.min_width = -params.min_width;
      if (!(params.flags & FLAG_PADD_RIGHT))
	params.flags += FLAG_PADD_RIGHT;
    }
  i += get_precision(&(format[i]), &params, args);
  params.conv_spec = format[i];
  if (do_conv(&params, args, len))
    {
      i = -1 + (params.conv_spec == '%');
      my_putchar('%');
    }
  return (i + 1);
}
