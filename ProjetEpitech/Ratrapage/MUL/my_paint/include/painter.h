/*
** painter.h for painter in /home/daniel_d/rendu/MUL/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 12:29:35 2014 daniel_d
** Last update Wed Jul  9 11:35:44 2014 daniel_d
*/

#ifndef PAINTER_H_
# define PAINTER_H_

/* paramétre window*/
#define NAMEPAINT	"Pimp my Paint"
#define WINX		1200
#define WINY		1000
#define NAMECOLOR	"Pimp my Paint color"
#define COLORX		350
#define COLORY		100
#define NAMEMENU	"Pimp my Paint menu"
#define MENUX		204
#define MENUY		600

/* touches */
#define ECHAP	65307
#define LC	1
#define ZERO	'a'
#define ONE	'z'
#define TWO	'e'
#define THREE	'r'
#define FOUR	'c'
#define EP	't'
#define REMP	'y'

/* mode */
#define BRUSH		1
#define SQUARE		2
#define CIRCLE		3
#define TRIANGLE	4
#define EP1		1
#define EP2		2
#define EP3		3

/* color panel*/
#define BG	0xFFFFFF
#define RED	0xFF0000
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define PURPLE	0x990099
#define CYAN	0x00FFFF
#define YELLOW	0xFFFF00
#define BROWN	0x663300
#define ORANGE	0xFF6600
#define BLACK	0x000000
#define WHITE	0xFFFFFF

#define GRAY	0x444444

/* obj rayon draw */
#define SQUARE_S	50
#define CIRCLE_S	50
#define TRIANGLE_S	50

/*obj rayon menu*/
#define CR		30
#define BR		5
#define SR		20
#define TR		15
#define RR		20
#define RS		10

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
  void	*win_menu;
  void	*img_menu;
  t_painter *paint;
} t_window;

/* brush.c */
void		brush_mode(t_window *win);
void		brush_size_bis(t_window *win);
void		brush_size(t_window *win);
void		brush(t_window *win);

/* color_click.c */
int		take_color(int keycode, int x, int y, t_window *win);
t_window	*color_select(t_window *win);
t_window        *color_down(t_window *win, int x);
t_window        *color_top(t_window *win, int x);

/* draw.c */
t_painter       *init_paint(t_painter *paint);
t_window        *draw(t_window *win);

/* main.c */
t_window	*init_background(t_window *win);
int		main_painter(t_window *win);
void		usage();
int		main();

/* my_put_pixel_to_image.c */
void		*my_pixel_put_to_image(void *img_ptr, int x,
			       int y, unsigned int color);
/* remp.c */
void		remp_tri(int keycode, t_window *win);

/* triangle.c */
void		triangle_line(t_window *win, int i, int l, t_coord coord);
void		triangle(t_window *win);
void		draw_triangle_line(t_window *win);
void		triangle_remp(t_window *win);

/* circle.c */
void		circle(t_window *win);
void		circle_remp(t_window *win);

/* color_win.c */
unsigned int	*init_tab(unsigned int *tab);
t_window        *color_square(t_coord_square coord,
                              t_window *win, unsigned int color);
t_coord_square  init_coord(t_coord_square coord, int *i);
t_window        *color_prep(t_window *win);
t_window        *color_win(t_window *win);

/* expose.c */
int		gere_expose_paint(t_window *win);
int		gere_expose_color(t_window *win);
int		gere_expose_menu(t_window *win);

/* menu.c */
int		take_option(int keycode, int x, int y, t_window *win);
void		draw_mid(t_window *win, int y);
void		draw_limite(t_window *win);
t_window        *color_menu(t_window *win);
t_window        *menu(t_window *win);

/* option.c */
int		gere_mouse(int  keycode, int x, int y, t_window *win);
int		gere_end(int keycode, t_window *win);
int		gere_key(int keycode, t_window *win);

/* square.c */
void		square_1(t_window *win, t_coord_square cor);
void		square_2(t_window *win, t_coord_square cor);
void		square(t_window *win);
void		square_remp(t_window *win);

/* bouton/bouton_brush.c */
void		clean_bouton_brush(t_window *win);
void		remp_bouton_brush(t_window *win);
void		bouton_brush(t_window *win, int x, int y);
void		bouton_brush_aff(t_window *win);

/* bouton/bouton_remp.c */
void		clean_bouton_remp(t_window *win);
void		remp_bouton_remp(t_window *win);
void		bouton_remp(t_window *win, int x, int y);
void		bouton_remp_aff(t_window *win);

/* bouton/bouton_remp.c */
void		clean_bouton_circle(t_window *win);
void		remp_bouton_circle(t_window *win);
void		bouton_circle(t_window *win, int x, int y);
void		bouton_circle_aff(t_window *win);

/* bouton/bouton_square.c */
void		clean_bouton_square(t_window *win);
void		remp_bouton_square(t_window *win);
void		bouton_square(t_window *win, int x, int y);
void		bouton_remp_aff_remp(t_window *win);
void		bouton_square_aff(t_window *win);

/* bouton/bouton_size.c */
void		bouton_size(t_window *win, int x, int y);
void		bouton_size_aff_1(t_window *win);
void		bouton_size_aff_2(t_window *win);
void		bouton_size_aff_3(t_window *win);

/* bouton/bouton_size_clean.c*/
void		clean_bouton_size1(t_window *win);
void		clean_bouton_size2(t_window *win);
void		clean_bouton_size3(t_window *win);

/* bouton/bouton_size_remp.c */
void		remp_bouton_size1(t_window *win);
void		remp_bouton_size2(t_window *win);
void		remp_bouton_size3(t_window *win);

/* bouton/bouton_triangle.c */
void		clean_bouton_triangle(t_window *win);
void		remp_bouton_triangle(t_window *win);
void		bouton_triangle(t_window *win, int x, int y);
void		bouton_triangle_line(t_window *win, int i, int l,
				     t_coord coord);
void		bouton_triangle_aff(t_window *win);

#endif
