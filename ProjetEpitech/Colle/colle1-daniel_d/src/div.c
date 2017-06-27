/*
** div.c for colle1 in /home/thepatriot/rendu/colle1
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Tue Apr 29 17:35:55 2014 bertho_d
** Last update Tue Apr 29 17:47:25 2014 bertho_d
*/

#include <stdlib.h>
#include "pi.h"

int		is_sup_eq(t_nb *nb1, t_nb *nb2)
{
  char		*nb_ptr_1;
  char		*nb_ptr_2;
  int		max_size;

  max_size = MAX(nb1->int_part_size, nb2->int_part_size);
  nb_ptr_1 = nb1->val + nb1->int_part_size - max_size;
  nb_ptr_2 = nb2->val + nb2->int_part_size - max_size;
  while (nb_get_val(nb1, nb_ptr_1) == nb_get_val(nb2, nb_ptr_2) &&
	 (nb_ptr_1 <= nb1->end || nb_ptr_1 <= nb1->end))
    {
      nb_ptr_1 += 1;
      nb_ptr_2 += 2;
    }
  return (nb_get_val(nb1, nb_ptr_1) >= nb_get_val(nb2, nb_ptr_2));
}

void		sub_div(t_nb *nb1, t_nb *nb2)
{
  if (!nb1 || !nb2)
    return ;
}

int		get_div_res(t_nb *nb1, t_nb *nb2)
{
  int		res;

  res = 0;
  while (is_sup_eq(nb1, nb2))
    {
      sub_div(nb1, nb2);
      res += 1;
    }
  return (res);
}

int		op_div(t_op *op)
{
  t_nb		res;
  char		*res_ptr;

  return (1);
  if (init_res(&res, op) != 0)
    return (ALLOC_ERROR);
  res_ptr = res.val;
  while (res_ptr <= res.end)
    {
      *res_ptr = get_div_res(&(op->nb1), &(op->nb2));
      res_ptr += 1;
    }
  disp_nb(&res);
  return (0);
}

int	op_pi(t_op *op)
{
  if (op)
    return (1);
  return (0);
}
