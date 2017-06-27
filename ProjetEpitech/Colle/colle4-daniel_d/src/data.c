/*
** data.c for data in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 14:17:03 2014 marrec_k
** Last update Wed May 21 16:56:03 2014 marrec_k
*/

#include <stdlib.h>
#include "boogle.h"

void	my_init_data(t_data *data)
{
  data->size = 4;
  data->grid = NULL;
  data->word = NULL;
  data->color = 0;
  data->save = NULL;
}

void	my_get_size(t_data *data, char **tab, int *i)
{
  if (my_strcmp("-s", tab[*i]) == 0 && tab[*i + 1])
    {
      data->size = my_getnbr(tab[*i + 1]);
      *i += 1;
    }
}

void	my_get_grid_and_word(t_data *data, char **tab, int *i)
{
  if (my_strcmp("-g", tab[*i]) == 0 && tab[*i + 1])
    {
      data->grid = my_strdup(tab[*i + 1]);
      *i += 1;
    }
  else if (my_strcmp("-w", tab[*i]) == 0 && tab[*i + 1])
    {
      data->word = my_strdup(tab[*i + 1]);
      *i += 1;
    }
}

void	my_get_color_option(t_data *data, char **tab, int *i)
{
  if (my_strcmp("--color", tab[*i]) == 0)
    data->color = 1;
}

int	my_get_data(t_data *data, char **tab)
{
  int	i;

  i = 1;
  while (tab[i])
    {
      my_get_size(data, tab, &i);
      my_get_grid_and_word(data, tab, &i);
      my_get_color_option(data, tab, &i);
      i += 1;
    }
  return (0);
}
