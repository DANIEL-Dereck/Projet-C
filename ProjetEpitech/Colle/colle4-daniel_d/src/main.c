/*
** main.c for main in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 14:04:50 2014 marrec_k
** Last update Wed May 21 17:39:04 2014 daniel_d
*/

#include "boogle.h"

void	my_help(char *name)
{
  my_putstr(name);
  my_putstr(" [-s SIZE] [-g GRID] [-w WORD] --color\n");
  my_putstr("[-s SIZE] : Define the size of the grid | Default : 4\n");
  my_putstr("[-g GRID] : Define the grid | Default : A random grid is made\n");
  my_putstr("[-w WORD] : Define the word to search | ");
  my_putstr("Default : Standard Input\n");
  my_putstr("--color : Show the solution with color\n");
}

void	my_not_found(char *word)
{
  my_putstr("The word '");
  my_putstr(word);
  my_putstr("' isn't in the grid\n");
}

void	my_game(t_data *data)
{
  if (data->word)
    {
      if (my_check_word_in_grid(data) == 0)
	my_show_grid(data);
      else
	my_not_found(data->word);
    }
  else
    {
      my_show_grid(data);
      my_putchar('>');
      while ((data->word = get_next_line(0))
	     && my_check_word_in_grid(data) == 1)
	{
	  my_not_found(data->word);
	  my_putchar('>');
	}
      my_show_grid(data);
    }
}

int	main(int ac, char **av)
{
  t_data	data;

  if (ac == 2 && my_strcmp("--help", av[1]) == 0)
    {
      my_help(av[0]);
      return (0);
    }
  my_init_data(&data);
  if (my_get_data(&data, av) == 1)
    return (1);
  if (my_check(&data) == 1)
    return (1);
  if (!(data.grid) && !(data.grid = my_generate_grid(data.size)))
    return (1);
  my_game(&data);
  return (0);
}
