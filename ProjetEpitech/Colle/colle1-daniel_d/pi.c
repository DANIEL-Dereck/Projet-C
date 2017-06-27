/*
** my_pi.c for colle1 in /home/daniel_d/colle1-daniel_d
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr 29 15:48:14 2014 daniel_d
** Last update Tue Apr 29 17:48:45 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_pi.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}

int	my_pi_preci(t_op *op, double result)
{
  int	i;
  int	res;
  int	preci;
  char	*pi;

  i = 0;
  preci = op->precision + 2;
  if ((pi = malloc(sizeof(pi) * (preci))) == NULL)
    return (-1);
  res = result / 1.0;
  pi[0] = (res % 10) + '0';
  pi[1] = ',';
  while (preci > 0)
    {
      if (pi[i] != ',')
	{
	  result = result * 10;
	  res = result / 1.0;
	  pi[i] = (res % 10) + '0';
	}
      i++;
      preci--;
    }
  my_putstr(pi);
  my_putchar('\n');
  return (0);
}

int		my_pi_prof(t_op *op)
{
  int		prof;
  double	i;
  double	result;

  i = 1;
  result = 0;
  prof = op->profondeur;
  while (prof >= 0)
    {
      result = result + ((4.0 / i) - (4.0 / (i + 2.0)));
      i = i + 4.0;
      prof--;
    }
  if (my_pi_preci(op, result) == -1)
    return (-1);
  return (0);
}

int	main()
{
  t_op	*op;

  if ((op = malloc(sizeof(op))) == NULL)
    return (0);
  op->profondeur = PROFONDEUR;
  op->precision = PRECISION;
  my_pi_prof(op);
}
