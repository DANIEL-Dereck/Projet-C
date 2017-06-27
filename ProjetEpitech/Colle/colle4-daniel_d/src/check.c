/*
** check.c for check in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 14:40:39 2014 marrec_k
** Last update Wed May 21 17:27:58 2014 marrec_k
*/

#include "boogle.h"

int	my_check_grid(char *grid)
{
  int	i;

  i = 0;
  while (grid && grid[i])
    {
      if (grid[i] < 'a' || grid[i] > 'z')
	return (1);
      i += 1;
    }
  return (0);
}

int	my_check(t_data *data)
{
  if (data->size <= 0)
    return (my_puterror("[ERROR] : Size must be strictely positive\n", 1));
  if (data->size > 50)
    return (my_puterror("[ERROR] : Size is too huge\n", 1));
  if (data->grid && my_strlen(data->grid) != data->size * data->size)
    return (my_puterror("[ERROR] : Invalid Grid - Bad length\n", 1));
  if (data->grid && my_check_grid(data->grid) == 1)
    {
      my_puterror("[ERROR] : Invalid Grid - Bad char\n", 1);
      my_puterror("Allowed Chars : ", 1);
      return (my_puterror("\"abcdefghijklmnopqrstuvwxyz\"\n", 1));
    }
  if (data->word && my_check_grid(data->word) == 1)
    {
      my_puterror("[ERROR] : Invalid Word - Bad char\n", 1);
      my_puterror("Allowed Chars : ", 1);
      return (my_puterror("\"abcdefghijklmnopqrstuvwxyz\"\n", 1));
    }
  return (0);
}
