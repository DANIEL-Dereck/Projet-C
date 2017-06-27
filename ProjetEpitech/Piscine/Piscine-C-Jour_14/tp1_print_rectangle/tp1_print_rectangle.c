/*
** tp1_print_rectangle.c for tp1_windows_empty in /home/daniel_d/rendu/Piscine-C-Jour_14/tp1_print_rectangle
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Oct 24 11:01:00 2013 daniel_d
** Last update Thu Nov  7 17:55:53 2013 daniel_d
*/

int	main(int argc, char **argv)
{
  void	*mlx_ptr;
  void	*win_ptr;
  int x;
  int y;
  int xmax;
  int ymax;
  int k;
  int a;
  int f;
  int u;

  x = 100;
  y = 100;
  k = y;
  f = x;
  u = y;
  xmax = 750;
  ymax = 750;
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "My first window");
  while (x < xmax)
    {
      while (y < ymax)
	{
	  mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FFFFFF);
	  y = y + 1;
	}
      y = k;
      x = x + 1;
    }
   while (42);
   {

   }
   return (0);
}
