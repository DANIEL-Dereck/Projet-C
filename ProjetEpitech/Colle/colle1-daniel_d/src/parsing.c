/*
** main.c for colle1 in /home/daniel_d/colle1-daniel_d
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr 29 14:09:20 2014 daniel_d
** Last update Tue Apr 29 16:32:00 2014 bertho_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "pi.h"

int		expected_val(char *option)
{
  if (!option)
    return (-1);
  PUTERR("expected value for option \"");
  PUTERR(option);
  PUTERR("\"\n");
  return (-1);
}

int		invalid_option(char *option)
{
  if (!option)
    return (-1);
  PUTERR("invalid option: \"");
  PUTERR(option);
  PUTERR("\"\n");
  return (-1);
}

int		get_op_type(t_op *op, int i, char **av)
{
  t_optype	type;

  if (av[i][0] == '-' && av[i][1] == 'a' && av[i][2] == '\0')
    type = ADD;
  else if (av[i][0] == '-' && av[i][1] == 's' && av[i][2] == '\0')
    type = SUB;
  else if (av[i][0] == '-' && av[i][1] == 'd' && av[i][2] == '\0')
    type = DIV;
  else
    return (invalid_option(av[i]));
  if (av[i + 1] && av[i + 2])
    return (set_op(op, type, av[i + 1], av[i + 2]));
  PUTERR("expected two values for option ");
  PUTERR(av[i]);
  PUTERR("\n");
  return (-1);
}

int		parse(t_op *op, char **av)
{
  int		i;

  i = 0;
  while (av[++i] != NULL)
    {
      if (av[i][0] == '-' && av[i][1] == 'p' && av[i][2] == '\0')
	{
	  if (!(av[++i]))
	    return (expected_val(av[i - 1]));
	  op->depth = my_atoi(av[i]);
	}
      else if (av[i][0] == '-' && av[i][1] == 'P' && av[i][2] == '\0')
	{
	  if (!(av[++i]))
	    return (expected_val(av[i - 1]));
	  op->precision = my_atoi(av[i]);
	}
      else if (get_op_type(op, i, av) == 0)
	i += 2;
      else
	return (-1);
    }
  return (0);
}

int		parsing(int ac, char **av, t_op *op)
{
  op->type = PI;
  op->depth = DFLT_DEPTH;
  op->precision = DFLT_PRECISION;
  if (ac > 1 && parse(op, av) != 0)
    return (-1);
  if (op->depth <= 0)
    {
      PUTERR("depth must be positive\n");
      return (-1);
    }
  if (op->precision >= 0)
    return (0);
  PUTERR("precision must be positive\n");
  return (-1);
}
