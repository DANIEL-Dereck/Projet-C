/*
** padding.c for my_printf in /home/bertho_d/rendu/Piscine-C-lib/my/my_io/my_printf
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sun Nov 10 18:49:32 2013 bertho_d
** Last update Thu Nov 21 10:57:38 2013 bertho_d
*/

#include "my.h"
#include "my_printf.h"

static void	hexa_alter_form(long nb, t_params *params)
{
  if ((params->flags & FLAG_ALTER_FORM) && nb)
    {
      if (params->conv_spec == 'x')
	my_putstr("0x");
      else if (params->conv_spec == 'X')
	my_putstr("0X");
    }
}

static void	disp_sign(int nb, t_params *params)
{
  if (nb < 0)
    my_putchar('-');
  else if (params->flags & FLAG_SIGN_PLUS)
    my_putchar('+');
  else if (params->flags & FLAG_SIGN_BLANK)
    my_putchar(' ');
}

static int	precision(long nb, int sign, int nb_len, t_params *params)
{
  int	nb_zeroes;

  if (!nb && (params->precision == -1) && !(params->flags & FLAG_PADD_ZERO))
    nb_zeroes = 1;
  else
    nb_zeroes = (((params->flags & FLAG_PADD_ZERO)
		  && !(params->flags & FLAG_PADD_RIGHT)
		  && params->precision == -1)
		 ? params->min_width - sign
		 : params->precision) - nb_len;
  if (nb_zeroes < 0)
    nb_zeroes = 0;
  return (nb_zeroes);
}

int	padding(int left, int len, t_params *params)
{
  if (!(left && !(params->flags & FLAG_PADD_RIGHT)) &&
      !(!left && (params->flags & FLAG_PADD_RIGHT)))
    return (0);
  my_put_n_chars(' ', params->min_width - len);
  return ((params->min_width - len > 0) ? params->min_width - len : 0);
}

int	display(long nb, int is_signed, char *base, t_params *params)
{
  int	nb_zeroes;
  int	nb_len;

  nb_len = calc_u_nb_len(((nb < 0 && is_signed) ? -nb : nb), my_strlen(base));
  nb_zeroes = precision(nb, 0, nb_len, params);
  nb_len += (is_signed && ((nb < 0) || (params->flags & FLAG_SIGN_PLUS) ||
			   (params->flags & FLAG_SIGN_BLANK)))
    + ((params->flags & FLAG_ALTER_FORM) && nb &&
       (params->conv_spec == 'x' || params->conv_spec == 'X')) * 2;
  if (params->conv_spec == 'o' && (params->flags & FLAG_ALTER_FORM))
    nb_zeroes = ((nb_zeroes) ? nb_zeroes : 1);
  if (!((params->flags & FLAG_PADD_ZERO)
	&& !(params->flags & FLAG_PADD_RIGHT)
	&& params->precision == -1))
    nb_len += padding(1, nb_len + nb_zeroes, params);
  hexa_alter_form(nb, params);
  if (is_signed)
    disp_sign(nb, params);
  my_put_n_chars('0', nb_zeroes);
  if (nb)
    my_ulong_putnbr_base(((nb < 0 && is_signed) ? -nb : nb), base);
  nb_len += padding(0, nb_zeroes + nb_len, params);
  return (nb_len + nb_zeroes);
}
