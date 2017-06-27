/*
** instantk.c for 101pong in /home/daniel_d/rendu/101pong
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Nov 11 11:02:23 2013 daniel_d
** Last update Tue Nov 19 17:03:10 2013 daniel_d
*/

#include "my.h"
#include "pong.h"

int	coorvec(char *abst1, char *ordt1, char *lat1, char *abst, char *ordt, char *lat)
{
  int	x;
  int	y;
  int	l;
 
  l = my_getnbr(lat) - my_getnbr(lat1);
  y = my_getnbr(ordt) - my_getnbr(ordt1);
  x = my_getnbr(abst) - my_getnbr(abst1);
  my_putstr("Les coordonnées du vecteur vitesse sont (");
  my_put_nbr(x);
  my_putchar(';');
  my_put_nbr(y);
  my_putchar(';');
  my_put_nbr(l);
  my_putstr(").\n");
  return (0);
}
