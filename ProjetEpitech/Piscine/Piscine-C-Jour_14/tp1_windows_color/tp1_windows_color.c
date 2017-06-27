/*
** tp1_windows_color.c for tp1_windows_color in /home/daniel_d/rendu/Piscine-C-Jour_14/tp1_windows_color
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Oct 24 11:01:00 2013 daniel_d
** Last update Mon May  5 14:40:33 2014 daniel_d
*/

int	main()
{
  void	*mlx_ptr;
  void	*win_ptr;

  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "My first window");
  mlx_pixel_put(mlx_ptr, win_ptr, 500, 500, 0xFFFFFF);
  while (42);
  return (0);
}
