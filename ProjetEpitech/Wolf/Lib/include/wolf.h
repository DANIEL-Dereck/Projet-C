/*
** tpwolf.h for wolf in /home/daniel_d/TP/Wolf3d/Wolf3d-TP/Lib/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jan 10 09:17:43 2014 daniel_d
** Last update Sun Jan 12 23:25:34 2014 daniel_d
*/

#ifndef WOLF_H_
# define WOLF_H_

#define WSX 1024
#define WSY 768

#define COLORS 0x0000518E
#define COLORW 0x003F3F3F
#define COLORG 0x00006425

#define XMAP 10
#define YMAP 10

typedef struct s_window
{
  void	*mlx;
  void	*win;
  void	*img2_ptr;
} t_window;

typedef struct s_myimg
{
  void	*img_ptr;
  int	y;
  int	x;
  int	z;
} t_myimg;

typedef struct s_tr
{
  double	p;
  double	d;
  int	x;
  int	y;
  double	xp;
  double	yp;
  double	x1;
  double	y1;
  double	xpp;
  double	ypp;
  double	k;
} t_tr;

int     my_wolf();
void    *my_pixel_put_to_image(void *img_ptr, int x, int y, unsigned int color);
int     wolfkey(int keycode);
t_myimg	my_wolfsky(t_myimg image);
t_myimg aff_wall_line(t_myimg image, double k, int x);
t_myimg	my_wolfground(t_myimg image);
void	my_wolf_wall();
t_tr    my_calc_wolfx();
void    affshellmap();
void    *clear_image(void *img_ptr, int x, int  y);
int     gere_expose();


#endif
