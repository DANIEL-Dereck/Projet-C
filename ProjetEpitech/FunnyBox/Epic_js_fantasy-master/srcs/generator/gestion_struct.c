/*
** gestion_strcut.c for rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 16:57:02 2014 daniel_d
** Last update Sat May 10 18:10:31 2014 cordon_b
*/

#include "rush.h"

int     remp_header(int fd)
{
  t_headerg     *h;

  if ((h = malloc(sizeof(*h))) == NULL)
    return (-1);
  h = init_header(h);
  header(fd, h);
  return (0);
}

int     remp_champion(int fd)
{
  t_championg   *c;
  int   i;

  i = 0;
  if ((c = malloc(sizeof(*c))) == NULL)
    return (-1);
  while (i <= CMAX)
    {
      c = init_champion(c);
      champion(fd, c);
      i++;
    }
  return (0);
}

int     remp_monster(int fd)
{
  t_monsterg    *m;
  int   i;

  i = 0;
  if ((m = malloc(sizeof(*m))) == NULL)
    return (-1);
  while (i <= MMAX)
    {
      m = init_monster(m);
      monster(fd, m);
      i++;
    }
  return (0);
}

int     remp_room(int fd)
{
  t_roomg       *r;
  int   i;

  i = 0;
  if ((r = malloc(sizeof(*r))) == NULL)
    return (-1);
  while (i <= RMAX)
    {
      r = init_room(r);
      room(fd, r);
      i++;
    }
  return (0);
}
