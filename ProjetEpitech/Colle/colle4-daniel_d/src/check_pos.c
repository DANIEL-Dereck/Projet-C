/*
** check_pos.c for check_pos in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 17:04:29 2014 marrec_k
** Last update Wed May 21 17:46:20 2014 daniel_d
*/

#include "boogle.h"

int	my_check_pos_in_save(int *save, int pos)
{
  int	i;

  i = 0;
  while (save && save[i] != -1)
    {
      if (save[i] == pos)
        return (1);
      i += 1;
    }
  return (0);
}

int	my_check_left(t_data *data, int *i, int j)
{
  if (*i % data->size > 0 && *i - 1 >= 0
      && data->grid[*i - 1] == data->word[j]
      && my_check_pos_in_save(data->save, *i - 1) == 0)
    *i = *i - 1;
  else
    return (1);
  return (0);
}

int	my_check_right(t_data *data, int *i, int j)
{
  if (data->size > 1 &&
      *i % data->size != data->size - 1 && *i + 1 >= 0
      && data->grid[*i + 1] == data->word[j]
      && my_check_pos_in_save(data->save, *i + 1) == 0)
    *i = *i + 1;
  else
    return (1);
  return (0);
}

int	my_check_up(t_data *data, int *i, int j)
{
  if (*i - data->size >= 0
      && data->grid[*i - data->size] == data->word[j]
      && my_check_pos_in_save(data->save, *i - data->size) == 0)
    *i = *i - data->size;
  else
    return (1);
  return (0);
}

int	my_check_down(t_data *data, int *i, int j)
{
  if (*i + data->size < my_strlen(data->grid)
      && data->grid[*i + data->size] == data->word[j]
      && my_check_pos_in_save(data->save, *i + data->size) == 0)
    *i = *i + data->size;
  else
    return (1);
  return (0);
}
