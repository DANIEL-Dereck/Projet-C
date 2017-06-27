/*
** fill_champ.c for rush in /home/cordon_b/rendu/rush2/Epic_js_fantasy/srcs/Parse_Map
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Sat May 10 12:54:42 2014 cordon_b
** Last update Sun May 11 00:34:10 2014 cordon_b
*/

#include "rush.h"

int	check_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  if (i != 16)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	recup_info_champ(t_champ **element, char **tab)
{
  if (check_tab(tab) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (((*element) = malloc(sizeof(**element))) == NULL)
    {
      fprintf(stderr, "ERROR MALLOC \n");
      return (EXIT_FAILURE);
    }
  (*element)->name = strdup(tab[1]);
  (*element)->type = strdup(tab[3]);
  (*element)->health = atoi(tab[5]);
  (*element)->spe = atoi(tab[7]);
  (*element)->speed = atoi(tab[9]);
  (*element)->deg = atoi(tab[11]);
  (*element)->weapon = strdup(tab[13]);
  (*element)->armor = strdup(tab[15]);
  return (EXIT_SUCCESS);
}

int     add_in_list_champ(t_global **list, char **tab)
{
  t_champ        *tmp;
  t_champ        *element;

  element = malloc(sizeof(*element));
  if (element == NULL)
    return (EXIT_FAILURE);
  if ((recup_info_champ(&element, tab)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  element->next = NULL;
  element->prev = NULL;
  if ((*list)->champ == NULL)
    {
      (*list)->champ = element;
      return (EXIT_SUCCESS);
    }
  tmp = (*list)->champ;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = element;
  element->prev = tmp;
  return (EXIT_SUCCESS);
}

int	fill_champ(t_global *global, char *str)
{
  char	**tab;

  if ((tab = str_to_wordtab(str, ' ')) == NULL)
    return (EXIT_FAILURE);
  add_in_list_champ(&global, tab);
  return (EXIT_SUCCESS);
}
