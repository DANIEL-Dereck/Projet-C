/*
** my_plan.c for rt in /home/daniel_d/TP/TP_RT/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Feb 13 10:38:50 2014 daniel_d
** Last update Sun Mar 16 19:12:17 2014 daniel_d
*/

#include "mlx.h"
#include "mlx_int.h"
#include "my.h"
#include "rt.h"
#include "math.h"

int     rtplank(t_prime *all, int x, int y)
{
  float	key;

  all->im->x = 100 - all->ey->xe;
  all->im->y = (WSX / 2) - x - all->ey->ye;
  all->im->z = (WSY / 2) - y - all->ey->ze;
  if (all->im->z == 0)
    return (0);
  else
    {
      key = -(all->ey->ze / all->im->z);
      if (key > 0.00000001)
	{
	  all->k->kp = -(all->ey->ze / all->im->z);
	  return (1);
	}
      return (0);
    }
  return (0);
}
