/*
** generate.c for generate in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 15:00:37 2014 marrec_k
** Last update Wed May 21 15:18:25 2014 marrec_k
*/

#include <stdlib.h>
#include <time.h>
#include "boogle.h"

char	my_random_char(int i, int len)
{
  int	t;
  int	r;
  char	c;

  t = time(NULL);
  if (t == -1)
    return (0);
  srand(t);
  r = ((rand() + i) * (rand() - len)) % 26;
  if (r < 0)
    r *= -1;
  c = 'a' + r;
  return (c);
}

int	my_random_grid(char *grid, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      if (!(grid[i] = my_random_char(i, len)))
	return (1);
      i += 1;
    }
  grid[i] = 0;
  return (0);
}

char	*my_generate_grid(int size)
{
  char	*grid;
  int	len;

  len = size * size;
  if (!(grid = malloc(sizeof(*grid) * (len + 1))))
    {
      my_puterror("Malloc failed\n", 1);
      return (NULL);
    }
  if (my_random_grid(grid, len) == 1)
    return (NULL);
  return (grid);
}
