/*
** show_put.c for show and put in /home/aubry_f/rendu/42sh/setenv/src
** 
** Made by aubry_f
** Login   <aubry_f@epitech.net>
** 
** Started on  Sun May 11 21:41:01 2014 aubry_f
** Last update Sat May 17 11:28:07 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"

int     put_tail_list(t_list **list, char *envir)
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

void    show_list(t_list **list)
{
  t_list *tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      printf("%s\n", tmp->envir);
      tmp = tmp->next;
    }
}
