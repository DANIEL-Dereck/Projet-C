/*
** fill_monster.c for rush in /home/cordon_b/rendu/rush2/Epic_js_fantasy/srcs/Parse_Map
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Sat May 10 13:15:09 2014 cordon_b
** Last update Sun May 11 00:36:27 2014 cordon_b
*/

#include "rush.h"

int     check_tab_monster(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    i++;
  if (i != 14)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int     recup_info_monster(t_monster **element, char **tab)
{
  if (check_tab_monster(tab) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (((*element) = malloc(sizeof(**element))) == NULL)
    {
      fprintf(stderr, "ERROR MALLOC \n");
      return (EXIT_FAILURE);
    }
  (*element)->type = strdup(tab[1]);
  (*element)->health = atoi(tab[3]);
  (*element)->spe = atoi(tab[5]);
  (*element)->speed = atoi(tab[7]);
  (*element)->deg = atoi(tab[9]);
  (*element)->weapon = strdup(tab[11]);
  (*element)->armor = strdup(tab[13]);
  return (EXIT_SUCCESS);
}

int     add_in_list_monster(t_global **list, char **tab)
{
  t_monster        *tmp;
  t_monster        *element;

  element = malloc(sizeof(*element));
  if (element == NULL)
    return (EXIT_FAILURE);
  if ((recup_info_monster(&element, tab)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  element->next = NULL;
  element->prev = NULL;
  if ((*list)->monster == NULL)
    {
      (*list)->monster = element;
      return (EXIT_SUCCESS);
    }
  tmp = (*list)->monster;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = element;
  element->prev = tmp;
  return (EXIT_SUCCESS);
}

int     fill_monster(t_global *global, char *str)
{
  char	**tab;

  if ((tab = str_to_wordtab(str, ' ')) == NULL)
    return (EXIT_FAILURE);
  add_in_list_monster(&global, tab);
  return (EXIT_SUCCESS);
}
