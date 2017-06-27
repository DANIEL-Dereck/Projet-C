/*
** my_show_grid.c for my_show_grid in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 15:27:19 2014 marrec_k
** Last update Wed May 21 17:14:30 2014 marrec_k
*/

#include "boogle.h"

void	my_print_border(int size)
{
  int	i;

  i = 0;
  my_putchar('+');
  while (i < (size * 2 + 1))
    {
      my_putchar('-');
      i += 1;
    }
  my_putstr("+\n");
}

void	my_print_line(t_data *data, int i)
{
  int	count;

  count = 0;
  my_putstr("| ");
  while (count < data->size)
    {
      if (data->color == 1 && my_check_pos_in_save(data->save, i) == 1)
	{
	  my_putstr("\033[32m");
	  my_putchar(data->grid[i]);
	  my_putstr("\033[0m");
	}
      else
	my_putchar(data->grid[i]);
      my_putchar(' ');
      count += 1;
      i += 1;
    }
  my_putstr("|\n");
}

void	my_show_grid(t_data *data)
{
  int	i;
  int	line;

  i = 0;
  line = 0;
  my_print_border(data->size);
  while (line < data->size)
    {
      my_print_line(data, i);
      line += 1;
      i += data->size;
    }
  my_print_border(data->size);
}
