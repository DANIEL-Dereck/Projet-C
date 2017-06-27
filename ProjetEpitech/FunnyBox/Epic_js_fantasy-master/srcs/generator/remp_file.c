/*
** remp_file.c for remp_file in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 13:13:45 2014 daniel_d
** Last update Sat May 10 18:11:03 2014 cordon_b
*/

#include "rush.h"

int     add_file(int fd, char *option, char *str, int bool)
{
  if (write(fd, option, strlen(option)) == -1)
    return (-1);
  if (str != NULL)
    {
      if (write(fd, SPACE, 1) == -1)
        return (-1);
      if (write(fd, str, strlen(str)) == -1)
        return (-1);
    }
  if (bool == 0)
    {
      if (write(fd, SPACE, 1) == -1)
        return (-1);
    }
  else if (bool == 1)
    {
      if (write(fd, LF, 1) == -1)
        return (-1);
    }
  return (0);
}

int     header(int fd, t_headerg *h)
{
  int	retour_val;
  int	*verif;

  if ((verif = malloc(sizeof(verif) * 6)) == NULL)
    return (-1);
  verif[0] = add_file(fd, MAGIC_NUMBER, NULL, 1);
  verif[1] = add_file(fd, HEADER, NULL, 0);
  verif[2] = add_file(fd, NAME, h->name, 0);
  verif[3] = add_file(fd, ROOM_TO_WIN, h->room_to_win, 0);
  verif[4] = add_file(fd, ROOM_TO_START, h->room_to_start, 0);
  verif[5] = add_file(fd, SPE_SECTION, NULL, 1);
  retour_val = resum_error(verif, 9);
  free(verif);
  return (retour_val);
}

int     champion(int fd, t_championg *c)
{
  int	retour_val;
  int	*verif;

  if ((verif = malloc(sizeof(verif) * 10)) == NULL)
    return (-1);
  verif[0] = add_file(fd, CHAMPION, NULL, 0);
  verif[1] = add_file(fd, NAME, c->name, 0);
  verif[2] = add_file(fd, TYPE, c->type, 0);
  verif[3] = add_file(fd, HP, c->hp, 0);
  verif[4] = add_file(fd, SPE, c->spe, 0);
  verif[5] = add_file(fd, SPEED, c->speed, 0);
  verif[6] = add_file(fd, DEG, c->deg, 0);
  verif[7] = add_file(fd, WEAPON, c->weapon, 0);
  verif[8] = add_file(fd, ARMOR, c->armor, 0);
  verif[9] = add_file(fd, SPE_SECTION, NULL, 1);
  retour_val = resum_error(verif, 9);
  free(verif);
  return (retour_val);
}

int     monster(int fd, t_monsterg *m)
{
  int	retour_val;
  int	*verif;

  if ((verif = malloc(sizeof(verif) * 9)) == NULL)
    return (-1);
  verif[0] = add_file(fd, MONSTER, NULL, 0);
  verif[1] = add_file(fd, TYPE, m->type, 0);
  verif[2] = add_file(fd, HP, m->hp, 0);
  verif[3] = add_file(fd, SPE, m->spe, 0);
  verif[4] = add_file(fd, SPEED, m->speed, 0);
  verif[5] = add_file(fd, DEG, m->deg, 0);
  verif[6] = add_file(fd, WEAPON, m->weapon, 0);
  verif[7] = add_file(fd, ARMOR, m->armor, 0);
  verif[8] = add_file(fd, SPE_SECTION, NULL, 1);
  retour_val = resum_error(verif, 8);
  free(verif);
  return (retour_val);
}

int	room(int fd, t_roomg *r)
{
  int	retour_val;
  int	*verif;

  if ((verif = malloc(sizeof(verif) * 6)) == NULL)
    return (-1);
  verif[0] = add_file(fd, ROOM, NULL, 0);
  verif[1] = add_file(fd, NAME, r->name, 0);
  verif[2] = add_file(fd, ADV, r->adv, 0);
  verif[3] = add_file(fd, TAB_CONNECTION, r->tab_connection, 0);
  verif[4] = add_file(fd, TAB_MONSTER, r->tab_monster, 0);
  verif[5] = add_file(fd, SPE_SECTION, NULL, 1);
  retour_val = resum_error(verif, 5);
  free(verif);
  return (retour_val);
}
