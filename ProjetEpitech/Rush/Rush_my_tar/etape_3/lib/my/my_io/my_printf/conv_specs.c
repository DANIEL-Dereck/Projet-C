/*
** conv_specs.c for my_printf in /home/bertho_d/rendu/Piscine-C-lib/my/my_io/my_printf
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sun Nov 10 18:46:32 2013 bertho_d
** Last update Thu Nov 21 10:49:31 2013 bertho_d
*/

#include <unistd.h>
#include "my.h"
#include "my_printf.h"

static int	conv_spec_uint_base(unsigned int nb, t_params *params)
{
  char	*base;

  if (params->conv_spec == 'b')
    base = "01";
  else if (params->conv_spec == 'o')
    base = "01234567";
  else if (params->conv_spec == 'u')
    base = "0123456789";
  else if (params->conv_spec == 'x')
    base = "0123456789abcdef";
  else if (params->conv_spec == 'X')
    base = "0123456789ABCDEF";
  else
    return (0);
  return (display(nb, 0, base, params));
}

static int	conv_spec_c(char c, t_params *params)
{
  int	len;

  if (params->conv_spec != 'c')
    return (0);
  len = padding(1, 1, params);
  my_putchar(c);
  len += padding(0, 1, params) + 1;
  return (len);
}

static int	conv_spec_str(char *str, t_params *params)
{
  int	len;
  int	padd_len;

  if (params->conv_spec != 's' && params->conv_spec != 'S')
    return (0);
  if (!str && (params->precision > 5 || params->precision == -1))
    str = "(null)";
  len = my_strlen(str);
  if (len > params->precision && params->precision != -1)
    len = params->precision;
  padd_len = padding(1, len, params);
  if (params->conv_spec == 's')
    write(1, str, len);
  else
    my_showstr_n_base(str, len, "01234567");
  padd_len += padding(0, len, params);
  return (len + padd_len);
}

static int	conv_spec_p(unsigned long address, t_params *params)
{
  if (params->conv_spec != 'p')
    return (0);
  params->conv_spec = 'x';
  if (!(params->flags & FLAG_ALTER_FORM))
    params->flags += FLAG_ALTER_FORM;
  return (display(address, 0, "0123456789abcdef", params));
}

int	do_conv(t_params *params, t_args *args, int *len)
{
  long	val;

  if (my_find_char(params->conv_spec, CONV_SPECIFIERS) != -1)
    val = ((params->target) ? args->args[params->target - 1]
	   : args->args[(args->actual_arg)++]);
  else
    {
      *len += 1;
      return (1);
    }
  if (params->conv_spec == 'd' || params->conv_spec == 'i')
    *len += display((int)val, 1, "0123456789", params);
  *len += conv_spec_uint_base(val, params);
  *len += conv_spec_c(val, params);
  *len += conv_spec_str((char *)val, params);
  *len += conv_spec_p(val, params);
  if (params->conv_spec == 'n')
    *((int *)val) = *len;
  return (0);
}
