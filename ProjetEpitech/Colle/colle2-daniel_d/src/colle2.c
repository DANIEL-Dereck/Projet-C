/*
** colle2.c for colle in /home/gautie_a/rendu/colle2-daniel_d
** 
** Made by gautie_a
** Login   <gautie_a@epitech.net>
** 
** Started on  Tue May  6 14:13:07 2014 gautie_a
** Last update Tue May  6 17:58:28 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "calculator.h"

t_nb	*new_nb(char *expr, int *i, int prio)
{
  t_nb	*nb;

  if (!(nb = malloc(sizeof(*nb))))
    return (0);
  nb->nb = my_getnbr(expr + *i);
  while (expr[*i] == '-' || expr[*i] == '+')
    *i += 1;
  while (expr[*i] >= '0' && expr[*i] <= '9')
    *i += 1;
  *i -= 1;
  nb->priority = prio;
  nb->done = 0;
  return (nb);
}

t_nb	*new_nb_bynb(int nbr, int prio)
{
  t_nb	*nb;

  if (!(nb = malloc(sizeof(*nb))))
    return (0);
  nb->nb = nbr;
  nb->priority = prio;
  nb->done = 0;
  return (nb);
}

void	add_maillon(t_nb **nb, t_nb *last)
{
  if (!*nb)
    {
      *nb = last;
      last->prev = last;
      last->next = last;
    }
  else
    {
      last->next = *nb;
      last->prev = (*nb)->prev;
      (*nb)->prev->next = last;
      (*nb)->prev = last;
    }
}

t_nb	*parse_expr(char *expr, int *size)
{
  t_nb	*nb;
  t_nb	*last;
  int	prio;
  int	i;

  nb = NULL;
  prio = 0;
  i = -1;
  while (expr[++i])
    {
      if (my_str_contains(OPS, expr[i]) && i > 0 &&
	  (expr[i] == '*' || expr[i] == '/' || expr[i] == '%'))
	prio = 1;
      else
	{
	  last = new_nb(expr, &i, prio);
	  add_maillon(&nb, last);
	  *size += 1;
	  if (prio == 1)
	    last->prev->priority = prio;
	  prio = 0;
	}
    }
  return (nb);
}

int	get_max_prio(t_core *core)
{
  int	i;
  int	max;
  t_nb	*cur;

  cur = core->list;
  i = -1;
  max = 0;
  while (++i < core->size)
    {
      if (cur->priority > max)
	max = cur->priority;
      cur = cur->next;
    }
  return (max);
}

int	get_nb_by_prio(t_core *core, int max)
{
  t_nb	*cur;
  int	index;

  index = 0;
  cur = core->list;
  while (cur->priority != max)
    {
      cur = cur->next;
      ++index;
    }
  return (index);
}

int	delete_maillon(t_nb *nb, t_core *core, int index)
{
  char	*newop;
  int	i;
  int	carry;

  nb->prev->next = nb->next;
  nb->next->prev = nb->prev;
  if (!(newop = malloc(core->size - 1)))
    return (0);
  i = -1;
  carry = 0;
  while (++i < core->size)
    if (i != index)
      newop[i - carry] = core->op[i];
    else
      carry = 1;
  free(core->op);
  core->op = newop;
  free(nb);
  return (1);
}

int	colle_do_op(int nb1, int nb2, char op)
{
  if (op == '+')
    return (nb1 + nb2);
  if (op == '-')
    return (nb1 - nb2);
  if (op == '*')
    return (nb1 * nb2);
  if (op == '/')
    return (nb1 / nb2);
  return (nb1 % nb2);
}

int	colle_op(t_core *core)
{
  int	i;
  int	max;
  int	index;
  t_nb	*cur;

  index = 0;
  while (core->size > 1)
    {
      cur = core->list;
      max = get_max_prio(core);
      index = get_nb_by_prio(core, max);
      i = -1;
      while (++i < index)
	cur = cur->next;
      cur->nb = colle_do_op(cur->nb, cur->next->nb,
			    core->op[index]);
      core->op[index] = 0;
      cur->priority = 0;
      delete_maillon(cur->next, core, index);
      core->size -= 1;
    }
  return (1);
}

char	*fill_op_tab(char *expr, int size)
{
  char	*op;
  int	i;
  int	j;
  int	par;

  if (!(op = malloc(size - 1)))
    return (NULL);
  par = 0;
  j = 0;
  i = -1;
  while (expr[++i])
    if (expr[i] == OPEN)
      ++par;
    else if (expr[i] == CLOSE)
      --par;
    else if (par == 0 && my_str_contains(OPS, expr[i]) && i > 0)
      op[j++] = expr[i];
  return (op);
}

int		colle2(char *expr)
{
  t_core	*core;

  if (!verif_expr(expr))
    {
      my_putstr("Syntax error\n");
      return (0);
    }
  if (!(core = malloc(sizeof(*core))))
    return (0);
  core->size = 0;
  core->del = 0;
  if (!(core->list = parse_expr(expr, &core->size)))
    return (0);
  if (!(core->op = fill_op_tab(expr, core->size)))
    return (0);
  colle_op(core);
  my_putnbr(core->list->nb);
  my_putchar('\n');
  return (core->list->nb);
}
