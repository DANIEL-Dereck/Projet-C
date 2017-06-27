/*
** my_env.c for  in /home/boucha_q/Downloads/my_42sh/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Fri May 23 13:15:33 2014 bouchard alexandre
** Last update Fri May 23 18:03:44 2014 bouchard alexandre
*/

#include "../include/sh.h"

void    my_env(t_list **list)
{
  t_list *tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      printf("%s\n", tmp->envir);
      tmp = tmp->next;
    }
}
