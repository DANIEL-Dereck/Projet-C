/*
** painter.h for painter in /home/daniel_d/rendu/MUL/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 12:29:35 2014 daniel_d
** Last update Thu Jun 26 21:16:00 2014 daniel_d
*/

#ifndef PAINTER_H_
# define PAINTER_H_

/* paramétre window*/
#define NAMEPAINT "Pimp my Paint"
#define WINX 1024
#define WINY 720
#define NAMECOLOR "Pimp my Paint color"
#define COLORX 350
#define COLORY 100

/* touches */
#define ECHAP 65307
#define LC 1
#define ZERO 'a'
#define ONE 'z'
#define TWO 'e'
#define THREE 'r'
#define FOUR 'c'
#define EP 't'
#define REMP 'y'

/* mode */
#define BRUSH 1
#define SQUARE 2
#define CIRCLE 3
#define TRIANGLE 4
#define EP1 1
#define EP2 2
#define EP3 3

/* color panel*/
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define PURPLE 0x990099
#define CYAN 0x00FFFF
#define YELLOW 0xFFFF00
#define BROWN 0x663300
#define ORANGE 0xFF6600
#define BLACK 0x000000
#define WHITE 0xFFFFFF

/* obj size */
#define SQUARE_S 50
#define CIRCLE_S 50
#define TRIANGLE_S 50

typedef struct s_coord
{
  int	x;
  int	y;
} t_coord;

typedef struct s_coord_square
{
  int	x1;
  int	y1;
  int	x2;
  int	y2;
} t_coord_square;

typedef struct s_painter
{
  unsigned int color;
  t_coord coord;
  t_coord cor;
  int	ep;
  int	keycode;
  int	color_mode;
  int	mode;
  int	remp;
} t_painter;

typedef struct s_window
{
  void	*mlx_ptr;
  void	*win_paint;
  void	*img_paint;
  void	*win_color;
  void	*img_color;
  t_painter *paint;
} t_window;

/* all */
void    usage();
void    *my_pixel_put_to_image(void *img_ptr, int x,
			       int y, unsigned int color);
int     gere_expose_paint(t_window *win);
int     gere_expose_color(t_window *win);
int     gere_mouse(int  keycode, int x, int y, t_window *win);
int     gere_end(int keycode, t_window *win);
int     gere_key(int keycode, t_window *win);
void	aff_mode(int keycode, t_window *win);

/* paint */
int     main_painter(t_window *win);
t_window	*init_background(t_window *win);
t_painter       *init_paint(t_painter *paint);
t_window        *draw(t_window *win);

/* color*/
unsigned int	*init_tab(unsigned int *tab);
t_window        *color_square(t_coord_square coord,
                              t_window *win, unsigned int color);
t_coord_square  init_coord(t_coord_square coord, int *i);
t_window        *color_prep(t_window *win);
t_window        *color_win(t_window *win);
int     take_color(int keycode, int x, int y, t_window *win);
t_window        *color_down(t_window *win, int x);
t_window        *color_top(t_window *win, int x);
void    color_key(t_window *win);
t_window	*color_select(t_window *win);

/* forme */
void    remp_tri(int keycode, t_window *win);
void	brush_mode(t_window *win);
void    brush(t_window *win);
void    line(t_window *win);
void    square(t_window *win);
void    circle(t_window *win);
void    triangle(t_window *win);
void	square_remp(t_window *win);
void	circle_remp(t_window *win);
void	triangle_remp(t_window *win);

/* menu*/
#endif
