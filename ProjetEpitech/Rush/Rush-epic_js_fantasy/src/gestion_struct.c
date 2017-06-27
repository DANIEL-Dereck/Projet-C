/*
** gestion_strcut.c for rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 16:57:02 2014 daniel_d
** Last update Sat May 10 21:23:22 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "epic_editor.h"

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
  int	laps;
  int   i;

  i = CMIN;
  if ((laps = question_prime("champion", CMIN, CMAX)) <= 0)
    return (-1);
  if ((c = malloc(sizeof(*c))) == NULL)
    return (-1);
  while (i <= laps)
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
  int	laps;
  int   i;

  i = MMIN;
  if ((laps = question_prime("monster", MMIN, MMAX)) <= 0)
    return (-1);
  if ((m = malloc(sizeof(*m))) == NULL)
    return (-1);
  while (i <= laps)
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
  int	laps;
  int   i;

  i = RMIN - 1;
  if ((laps = question_prime("room", RMIN, RMAX)) <= 0)
    return (-1);
  if ((r = malloc(sizeof(*r))) == NULL)
    return (-1);
  while (i <= laps)
    {
      r = init_room(r);
      room(fd, r);
      i++;
    }
  return (0);
}
