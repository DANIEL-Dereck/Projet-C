/*
** my_lists_base.c for libmy in /home/bertho_d/rendu/lib/my/my_lists
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sun Nov 24 19:02:44 2013 bertho_d
** Last update Thu Nov 28 15:31:58 2013 bertho_d
*/

#include <stdlib.h>
#include "my.h"

void	list_swap_elems(t_list *elem1, t_list *elem2)
{
  void	*temp;

  if (!elem1 || !elem2 || elem1 == elem2)
    return ;
  temp = elem1->data;
  elem1->data = elem2->data;
  elem2->data = temp;
}

void		list_free(t_list *list, int free_data)
{
  t_list	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      if (free_data)
	free(tmp->data);
      free(tmp);
    }
}

void		list_free_f(t_list *list, void (*free_data)())
{
  t_list	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      (*free_data)(tmp->data);
      free(tmp);
    }
}

t_list		*list_remove_elem(t_list *elem, int free_data)
{
  t_list	*next_elem;

  if (!elem)
    return (NULL);
  next_elem = elem->next;
  if (free_data)
    free(elem->data);
  free(elem);
  return (next_elem);
}

t_list		*list_new_elem(void *data, t_list *next)
{
  t_list	*elem;

  if (!(elem = malloc(sizeof(t_list))))
    return (NULL);
  elem->data = data;
  elem->next = next;
  return (elem);
}
