/*
** main.c for colle1 in /home/thepatriot/rendu/colle1
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Tue Apr 29 14:13:58 2014 bertho_d
** Last update Tue Apr 29 16:32:19 2014 bertho_d
*/

#include <stdlib.h>
#include "pi.h"

int		set_op(t_op *op, t_optype type, char *nb1, char *nb2)
{
  char		*inval;

  op->type = type;
  if (init_nb(&(op->nb1), (inval = nb1)) == 0 &&
      init_nb(&(op->nb2), (inval = nb2)) == 0)
    return (0);
  PUTERR("invalid number: ");
  PUTERR(inval);
  PUTERR("\n");
  return (-1);
}

int		main(int argc, char **argv)
{
  int		(*op_funcs[NB_OPS])(t_op *op);
  t_op		op;

  if (parsing(argc, argv, &op) || op.type < 0 || op.type >= NB_OPS)
    return (-1);
  op_funcs[ADD] = op_add;
  op_funcs[SUB] = op_sub;
  op_funcs[DIV] = op_div;
  op_funcs[PI] = op_pi;
  if (op_funcs[op.type](&op))
    {
      PUTERR("calc error\n");
      return (-1);
    }
  return (0);
}
