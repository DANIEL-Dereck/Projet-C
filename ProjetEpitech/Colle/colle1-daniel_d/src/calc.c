/*
** calc.c for colle1 in /home/thepatriot/rendu/colle1
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Tue Apr 29 14:26:35 2014 bertho_d
** Last update Tue Apr 29 17:35:48 2014 bertho_d
*/

#include <stdlib.h>
#include "pi.h"

int		init_res(t_nb *res, t_op *op)
{
  int		size;

  res->int_part_size = 1 + MAX(op->nb1.int_part_size, op->nb2.int_part_size);
  size = res->int_part_size + op->precision;
  if (!(res->val = malloc((size + 1) * sizeof(char))))
    return (ALLOC_ERROR);
  my_memset(res->val, '0', size);
  res->val[size] = '\0';
  res->end = res->val + size - 1;
  return (0);
}

int		op_add(t_op *op)
{
  t_nb		res;
  char		*nb_ptr_1;
  char		*nb_ptr_2;
  char		*res_ptr;

  if (init_res(&res, op) != 0)
    return (ALLOC_ERROR);
  res_ptr = nb_get_dec_ptr(&res) + op->precision - 1;
  nb_ptr_1 = nb_get_dec_ptr(&(op->nb1)) + op->precision - 1;
  nb_ptr_2 = nb_get_dec_ptr(&(op->nb2)) + op->precision - 1;
  while (nb_ptr_1 >= op->nb1.val || nb_ptr_2 >= op->nb2.val)
    {
      *res_ptr += (nb_get_val(&(op->nb1), nb_ptr_1)
		   + nb_get_val(&(op->nb2), nb_ptr_2));
      if (*res_ptr > (10 + '0'))
	{
	  *res_ptr -= 10;
	  *(res_ptr - 1) += 1;
	}
      res_ptr -= 1;
      nb_ptr_1 -= 1;
      nb_ptr_2 -= 1;
    }
  disp_nb(&res);
  return (0);
}

int		op_sub(t_op *op)
{
  t_nb		res;
  char		*nb_ptr_1;
  char		*nb_ptr_2;
  char		*res_ptr;

  if (init_res(&res, op) != 0)
    return (ALLOC_ERROR);
  res_ptr = nb_get_dec_ptr(&res) + op->precision - 1;
  nb_ptr_1 = nb_get_dec_ptr(&(op->nb1)) + op->precision - 1;
  nb_ptr_2 = nb_get_dec_ptr(&(op->nb2)) + op->precision - 1;
  while (nb_ptr_1 >= op->nb1.val || nb_ptr_2 >= op->nb2.val)
    {
      *res_ptr += (nb_get_val(&(op->nb1), nb_ptr_1)
		   - nb_get_val(&(op->nb2), nb_ptr_2));
      if (*res_ptr < '0')
	{
	  *res_ptr += 10;
	  *(res_ptr - 1) -= 1;
	}
      res_ptr -= 1;
      nb_ptr_1 -= 1;
      nb_ptr_2 -= 1;
    }
  disp_nb(&res);
  return (0);
}
