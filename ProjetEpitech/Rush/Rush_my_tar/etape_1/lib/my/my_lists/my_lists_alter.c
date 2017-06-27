/*
** my_llists.c for test in /home/bertho_d/rendu
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Tue Oct 29 17:43:21 2013 bertho_d
** Last update Wed Nov 27 11:49:35 2013 bertho_d
*/

#include "my.h"

t_list		*list_concat(t_list *l1, t_list *l2)
{
  t_list	*elem;

  if (!l2)
    return (l1);
  if (!l1)
    return (l2);
  elem = l1;
  while (elem->next)
    elem = elem->next;
  elem->next = l2;
  return (l1);
}

t_list		*list_rev(t_list *elem, t_list *prev)
{
  t_list	*next;

  if (!elem)
    return (prev);
  next = elem->next;
  elem->next = prev;
  return (list_rev(next, elem));
}

void		list_sort(t_list *begin, int (*cmp)())
{
  t_list	*lowest;
  t_list	*elem;

  if (!begin)
    return ;
  elem = begin;
  lowest = begin;
  while (elem->next)
    {
      elem = elem->next;
      if (cmp(lowest->data, elem->data) > 0)
	lowest = elem;
    }
  list_swap_elems(begin, lowest);
  list_sort(begin->next, cmp);
  return ;
}

void	list_apply_fct(t_list *list, int (*fct)(void*))
{
  if (!fct)
    return ;
  while (list)
    {
      (*fct)(list->data);
      list = list->next;
    }
}

void		list_rm_matching(t_list **list, int (*match)(), int free_data)
{
  t_list	*elem;

  if (!list || !(*list) || !match)
    return ;
  elem = *list;
  while (elem->next)
    {
      if (match(elem->next->data))
	elem->next = list_remove_elem(elem->next, free_data);
      else
	elem = elem->next;
    }
  if (match((*list)->data))
    *list = list_remove_elem(*list, free_data);
}
