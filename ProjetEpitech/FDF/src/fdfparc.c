/*
** fdfparc.c for fdf in /home/daniel_d/rendu/MUL_2013_fdf
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Dec  8 20:16:50 2013 daniel_d
** Last update Sun Dec  8 22:48:00 2013 daniel_d
*/

#include <stdlib.h>
#include <unistd.h>
#include "../Lib/include/my.h"
#include "../minilibx/mlx.h"

char	**fd_to_strtab(const int fd)
{
  char	**str;
  char	*buffer;
  int	l;
  int	r;

  l = 0;
  r = read(fd, buffer, 4096);
  if (r == 0)
    return (0);
  l = count_x_char(buffer, '\n');
  str = my_str_to_wordtab(buffer);
  return (str);
}

