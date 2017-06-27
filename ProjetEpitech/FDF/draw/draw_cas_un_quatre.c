/*
** draw_cas_un_quatre.c for FDF in /home/daniel_d/Prog-Test
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Dec  1 00:27:58 2013 daniel_d
** Last update Sun Dec  8 22:12:44 2013 daniel_d
*/

#include "../Lib/include/my.h"
#include "../minilibx/mlx.h"

int     draw_cas_quatre(void *mlx_ptr, void *win_ptr, int *tab)
{
  int x;
  int y;

  y = tab[2];
  while (y >= tab[3])
    {
      x = (tab[2] + ((tab[2] - tab[3]) * (x - tab[0])) / (tab[1] - tab[0]));
      mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FFFFFF);
      y--;
    }
  return (0);
}

int     draw_cas_trois(void *mlx_ptr, void *win_ptr, int *tab)
{
  int x;
  int y;

  y = tab[2];
  while (y <= tab[3])
    {
      x = (tab[2] + ((tab[3] - tab[2]) * (x - tab[0])) / (tab[1] - tab[0]));
      mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FFFFFF);
      y++;
    }
  return (0);
}

int     draw_cas_deux(void *mlx_ptr, void *win_ptr, int *tab)
{
  int x;
  int y;

  x = tab[0];
  while (x >= tab[1])
    {
      y = (tab[2] + ((tab[2] - tab[3]) * (x - tab[0])) / (tab[1] - tab[0]));
      mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FFFFFF);
      x--;
    }
  return (0);
}

int     draw_cas_un(void *mlx_ptr, void *win_ptr, int *tab)
{
  int x;
  int y;

  x = tab[0];
  while (x <= tab[1])
    {
      y = (tab[2] + ((tab[3] - tab[2]) * (x - tab[0])) / (tab[1] - tab[0]));
      mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FFFFFF);
      x++;
    }
  return (0);
}
