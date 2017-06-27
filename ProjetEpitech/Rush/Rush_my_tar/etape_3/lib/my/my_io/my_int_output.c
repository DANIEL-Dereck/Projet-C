/*
** my_output.c for libmy in /home/bertho_d/rendu/my_printf
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Nov  9 19:39:42 2013 bertho_d
** Last update Thu Nov 21 10:27:53 2013 bertho_d
*/

#include "my.h"

void	my_putnbr(int nb)
{
  int	signe;

  signe = 1;
  if (nb < 0)
    {
      signe = -1;
      my_putchar('-');
    }
  if (nb / 10 != 0)
    my_putnbr(signe * (nb / 10));
  my_putchar('0' + signe * (nb % 10));
}

void	my_u_putnbr(unsigned int nbr)
{
  if (nbr / 10 != 0)
    my_u_putnbr(nbr / 10);
  my_putchar('0' + nbr % 10);
}

void	my_putnbr_base(int nbr, char *base)
{
  int	base_type;
  int	signe;

  if (!base)
    return ;
  signe = 1;
  base_type = my_strlen(base);
  if (base_type < 1)
    return ;
  if (base_type == 1)
    {
      my_put_n_chars(base[0], nbr);
      return ;
    }
  if (nbr < 0)
    {
      my_putchar('-');
      signe = -1;
    }
  if (nbr / base_type != 0)
    my_putnbr_base(signe * nbr / base_type, base);
  my_putchar(base[signe * nbr % base_type]);
}

void	my_ulong_putnbr_base(unsigned long nbr, char *base)
{
  int	base_type;

  if (!base)
    return ;
  base_type = my_strlen(base);
  if (base_type < 1)
    return ;
  if (base_type == 1)
    {
      my_put_n_chars(base[0], nbr);
      return ;
    }
  if (nbr / base_type != 0)
    my_ulong_putnbr_base(nbr / base_type, base);
  my_putchar(base[nbr % base_type]);
}
