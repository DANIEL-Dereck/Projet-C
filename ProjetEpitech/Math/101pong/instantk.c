/*
** instantk.c for 101pong in /home/daniel_d/rendu/101pong
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Nov 11 11:02:23 2013 daniel_d
** Last update Fri Nov 15 16:16:49 2013 daniel_d
*/

#include "pong.h"
#include "my.h"

int	instantk(char *abst1, char *ordt1, char *lat1, char *abst, char *ordt, char *lat, char *instk)
{
  int	x;
  int	y;
  int	l;
  int	r;

  l = my_getnbr(lat) - my_getnbr(lat1);
  y = my_getnbr(ordt) - my_getnbr(ordt1);
  x = my_getnbr(abst) - my_getnbr(abst1);
  r = my_getnbr(instk);
  x = x * r;
  y = y * r;
  l = l * r;
  x = x + my_getnbr(abst);
  y = y + my_getnbr(ordt);
  l = l + my_getnbr(lat);
  my_putstr("A l’instant t+");
  my_put_nbr(my_getnbr(instk));
  my_putstr(", les coordonnées de la balle seront (");
  my_put_nbr(x);
  my_putchar(';');
  my_put_nbr(y);
  my_putchar(';');
  my_put_nbr(l);
  my_putstr(").\n");
  return (0);
}
