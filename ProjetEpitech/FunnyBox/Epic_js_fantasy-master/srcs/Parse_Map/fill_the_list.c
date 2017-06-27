/*
** fill_the_list.c for rush in /home/cordon_b/rendu/rush2/Epic_js_fantasy/srcs/Parse_Map
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Sat May 10 10:51:46 2014 cordon_b
** Last update Sun May 11 01:05:08 2014 cordon_b
*/

#include "rush.h"

int	fill_the_list(t_global *global, char *str, int flag)
{
  int (*fptr[6])(t_global *global, char *str);

  fptr[0] = &look_magic_number;
  fptr[1] = &fill_header;
  fptr[2] = &fill_champ;
  fptr[3] = &fill_monster;
  fptr[4] = &fill_link;
  fptr[5] = NULL;
  return (fptr[flag](global, str));
}
