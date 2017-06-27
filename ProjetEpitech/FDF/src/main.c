/*
** main.c for test in /home/daniel_d/Prog-Test
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Nov 28 16:37:30 2013 daniel_d
** Last update Sun Dec  8 22:52:33 2013 daniel_d
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../Lib/include/my.h"
#include "../minilibx/mlx.h"

int	main(int ac, char **av)
{
  void	*mlx_ptr;
  void	*win_ptr;
  char	**map;
  const	int fd;

  if (ac != 2)
    {
      my_putstr("Map error");
      return (0);
    }
  open(av[1], O_RDONLY);
  fd = av[1];
  map = fd_to_strtab(fd);
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdf daniel_d");
  while (42);
  return (0);
}
