/*
** rtm.c for rt in /home/daniel_d/TP/TP_RT/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Feb  6 09:13:43 2014 daniel_d
** Last update Mon Jun 23 14:33:16 2014 daniel_d
*/

#include <stdlib.h>
#include "mlx.h"
#include "mlx_int.h"
#include "my.h"
#include "rt.h"

t_prime	*ks(t_prime *all)
{
  if (all->k->ksf < all->k->kp)
    {
      all->k->kf = all->k->ksf;
      all->color->couleur = COLORS;
      all=lumos(all, 100, 100, 100);
    }
  else if (all->k->kp < all->k->ksf)
    {
      all->k->kf = all->k->kp;
      all->color->couleur = COLORP;
      all = lumos(all, 0, 0, 100);
    }
  return (all);
}

t_prime	*calcolor(t_prime *all, int x, int y)
{
  int	p;
  int	s;

  all->k = k_init(all->k);
  s = rtspherek(all, x, y);
  p = rtplank(all, x, y);
  if (s == 0 && p == 0)
    all->color->couleur = COLORF;
  else if (s == 1 && p == 0)
    {
      all->k->kf = all->k->ksf;
      all->color->couleur = COLORS;
      all = lumos(all, 100, 100, 100);
    }
  else if (s == 0 && p == 1)
    {
      all->k->kf = all->k->kp;
      all->color->couleur = COLORP;
      all = lumos(all, 0, 0, 100);
    }
  else if (s == 1 && p == 1)
    all = ks(all);
  return (all);
}

t_prime *verif_color(t_prime *all)
{
  if (all->color->red <= 0)
    all->color->red = 1;
  if (all->color->green <= 0)
    all->color->green = 1;
  if (all->color->blue <= 0)
    all->color->blue = 1;
  return (all);
}

t_prime	*affcolor(t_prime *all)
{
  int   x;
  int   y;

  y = 0;
  while (y <= WSY)
    {
      x = 0;
      while (x <= WSX)
        {
          all = calcolor(all, x, y);
	  all = verif_color(all);
          my_pixel_put_to_image(all->im->img_ptr
				, x++, y, all->color->couleur);
        }
      y++;
    }
  return (all);
}

int	rtmain()
{
  t_prime	*all;

  if ((all = malloc(sizeof(*all))) == NULL)
    return (ERROR);
  all = init_struct(all);
  all = eye_init(all);
  if ((all->wd->mlx = mlx_init()) == 0)
    {
      my_printf("ENV ERROR\n");
      return (0);
    }
  if ((all->wd->win = mlx_new_window(all->wd->mlx
				     , WSX, WSY, "RT-V1 daniel_d")) == 0)
    return (0);
  if ((all->im->img_ptr = mlx_new_image(all->wd->mlx, WSX, WSY)) == 0)
    return (0);
  all = affcolor(all);
  if ((mlx_put_image_to_window(all->wd->mlx, all->wd->win
			       , all->im->img_ptr, 0, 0)) == 0)
    return (0);
  all->wd->img2_ptr = all->im->img_ptr;
  mlx_key_hook(all->wd->win, gere_key, all);
  mlx_expose_hook(all->wd->win, gere_expose, all->wd);
  mlx_loop(all->wd->mlx);
  return (0);
}
