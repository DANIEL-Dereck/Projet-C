/*
** rt.h for rt.h in /home/daniel_d/rendu/MUL_2013_rtv1/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Mar 20 16:10:43 2014 daniel_d
** Last update Thu Mar 20 16:11:00 2014 daniel_d
*/

#ifndef RT_H_
# define RT_H_

#define ERROR -1
#define COLORF 0xA3FFE5
#define COLORP 0x303030
#define COLORS 0x00FF00
#define EYE -300
#define WSX 1500
#define WSY 1000
#define ZED 42

typedef struct s_window
{
  void  *mlx;
  void  *win;
  void  *img2_ptr;
} t_window;

typedef struct s_myimg
{
  void  *img_ptr;
  int   y;
  int   x;
  int   z;
} t_myimg;

typedef struct s_lumos
{
  float px;
  float py;
  float pz;
  float norm;
  float lx;
  float ly;
  float lz;
  float lumos;
  float alpha;
} t_lumos;

typedef struct s_color
{
  unsigned int couleur;
  int   red;
  int   green;
  int   blue;
} t_color;

typedef struct s_eye
{
  float xe;
  float ye;
  float ze;
} t_eye;

typedef struct s_sphere
{
  float a;
  float b;
  float c;
  float r;
  float d;
} t_sphere;

typedef struct s_k
{
  float kf;
  float ks1;
  float ks2;
  float ksf;
  float kp;
} t_k;

typedef struct s_prime
{
  t_window	*wd;
  t_myimg	*im;
  t_lumos	*lum;
  t_color	*color;
  t_sphere	*xyz;
  t_eye	*ey;
  t_k	*k;
}t_prime;

int     gere_expose(t_window *wd);
int     gere_key(int keycode, t_prime *all);
void    *my_pixel_put_to_image(void *img_ptr, int x,
			       int y, unsigned int color);
int     rtmain();
t_prime *affcolor(t_prime *all);
t_prime *calcolor(t_prime *all, int x, int y);
t_prime *ks(t_prime *all);
t_prime *lumos_color(t_prime *all);
t_prime *lumos(t_prime *all, float nx, float ny, float nz);
t_prime *init_struct(t_prime *all);
t_k     *k_init(t_k *k);
int     rtspherek(t_prime *all, int x, int y);
int     rtspherek2(t_prime *all);
int     rtplank(t_prime *all, int x, int y);
t_prime *colorpower(t_prime *all);
t_prime *eye_init(t_prime *all);

#endif

