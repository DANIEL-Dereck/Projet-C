/*
** fill_link.c for rush in /home/cordon_b/rendu/rush2/Epic_js_fantasy/srcs/Parse_Map
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Sat May 10 13:22:54 2014 cordon_b
** Last update Sun May 11 01:04:26 2014 cordon_b
*/

#include "rush.h"

int     check_tab_link(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    i++;
  if (i != 10)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int     recup_info_link(t_link **element, char **tab)
{
  if (check_tab_link(tab) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (((*element) = malloc(sizeof(**element))) == NULL)
    {
      fprintf(stderr, "ERROR MALLOC \n");
      return (EXIT_FAILURE);
    }
  (*element)->name = strdup(tab[1]);
  (*element)->adv = atoi(tab[3]);
  (*element)->liaison = str_to_wordtab(tab[5], '=');
  (*element)->tab = str_to_wordtab(tab[7], '=');
  return (EXIT_SUCCESS);
}

int     add_in_list_link(t_global **list, char **tab)
{
  t_link        *tmp;
  t_link        *element;

  element = malloc(sizeof(*element));
  if (element == NULL)
    return (EXIT_FAILURE);
  if ((recup_info_link(&element, tab)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  element->next = NULL;
  element->prev = NULL;
  if ((*list)->link == NULL)
    {
      (*list)->link = element;
      return (EXIT_SUCCESS);
    }
  tmp = (*list)->link;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = element;
  element->prev = tmp;
  return (EXIT_SUCCESS);
}

int	fill_link(t_global *global, char *str)
{
  char  **tab;

  if ((tab = str_to_wordtab(str, ' ')) == NULL)
    return (EXIT_FAILURE);
  add_in_list_link(&global, tab);
  return (EXIT_SUCCESS);
}
