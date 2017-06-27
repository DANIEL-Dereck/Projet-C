/*
** my_check_word_in_grid.c for my_check_word_in_grid in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 16:23:10 2014 marrec_k
** Last update Wed May 21 17:32:10 2014 marrec_k
*/

#include <stdlib.h>
#include "boogle.h"

int	*my_init_save(int len)
{
  int	*save;
  int	i;

  if (!(save = malloc(sizeof(*save) * (len + 1))))
    return (NULL);
  i = 0;
  while (i < len)
    {
      save[i] = -1;
      i += 1;
    }
  save[i] = -1;
  return (save);
}

void	my_add_pos(int *save, int pos)
{
  int	i;

  i = 0;
  while (save[i] != -1)
    i += 1;
  save[i] = pos;
}

void	my_solution(t_data *data)
{
  int	i;

  i = 0;
  while (data->save[i] != -1)
    {
      data->grid[data->save[i]] -= 32;
      i += 1;
    }
}

int	my_check_word_by_pos(t_data *data, int i)
{
  int	j;
  int	pos;

  j = 1;
  if (!(data->save = my_init_save(my_strlen(data->word))))
    return (1);
  while (data->word[j])
    {
      pos = i;
      if (my_check_left(data, &i, j) == 1
	  && my_check_right(data, &i, j) == 1
	  && my_check_up(data, &i, j) == 1
	  && my_check_down(data, &i, j) == 1)
	return (1);
      my_add_pos(data->save, pos);
      j += 1;
    }
  my_add_pos(data->save, i);
  return (0);
}

int	my_check_word_in_grid(t_data *data)
{
  int	i;
  int	j;

  i = 0;
  while (data->grid[i])
    {
      j = 0;
      if (data->grid[i] == data->word[j])
        {
          if (my_check_word_by_pos(data, i) == 0)
	    {
	      my_solution(data);
	      return (0);
	    }
        }
      i += 1;
    }
  return (1);
}
