/*
** init_strcut.c for init in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 14:36:51 2014 daniel_d
** Last update Sat May 10 21:17:48 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"
#include "epic_editor.h"

t_headerg	*init_header(t_headerg *h)
{
  h->name = strdup("name");
  h->room_to_win = strdup("room_to_win");
  h->room_to_start = strdup("room_to_start");
  return (h);
}

t_championg	*init_champion(t_championg *c)
{
  c->name = strdup("name");
  c->type = strdup("type");
  c->hp = strdup("hp");
  c->spe = strdup("spe");
  c->speed = strdup("speed");
  c->deg = strdup("deg");
  c->weapon = strdup("weapon");
  c->armor = strdup("armor");
  return (c);
}

t_monsterg	*init_monster(t_monsterg *m)
{
  m->type = strdup("type");
  m->hp = strdup("hp");
  m->spe = strdup("spe");
  m->speed = strdup("speed");
  m->deg = strdup("deg");
  m->weapon = strdup("weapon");
  m->armor = strdup("armor");
  return (m);
}

t_roomg	*init_room(t_roomg *r)
{
  r->name = strdup("name");
  r->adv = strdup("adv");
  r->tab_connection = strdup("tab_connection");
  r->tab_monster = strdup("tab_monster");
  return (r);
}
