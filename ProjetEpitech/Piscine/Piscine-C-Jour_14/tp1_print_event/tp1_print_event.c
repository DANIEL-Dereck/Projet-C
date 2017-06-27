/*
** tp1_print_event.c for tp1_windows_empty in /home/daniel_d/rendu/Piscine-C-Jour_14/tp1_print_event
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Oct 24 11:01:00 2013 daniel_d
** Last update Thu Nov  7 17:19:54 2013 daniel_d
*/

int	main()
{
  void	*mlx_ptr;
  void	*win_ptr;
  void	*mlx_loop;
  int	a;
  int	b;

  a = 50;
  b = 50;
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "My first window");
  mlx_pixel_put (mlx_ptr ,win_ptr ,a ,b ,0x00FFFFFF);
  a = a + 1;
  b = b + 1;
  mlx_loop(alt_F4);

}
