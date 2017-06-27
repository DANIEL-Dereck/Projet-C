/*
** my_put_tail_list.c for  in /home/boucha_q/Downloads/my_42sh/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Fri May 23 15:15:58 2014 bouchard alexandre
** Last update Sat May 24 11:38:27 2014 bouchard alexandre
*/

#include "../../include/sh.h"

int	put_tail_list(t_list **list, char *envir)
{
  t_list *new_elem;
  t_list *tmp;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (0);
  new_elem->envir = envir;
  new_elem->next = NULL;
  if (*list == NULL)
    {
      *list = new_elem;
      return (0);
    }
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
        tmp = tmp->next;
      tmp->next = new_elem;
      return (0);
    }
}
