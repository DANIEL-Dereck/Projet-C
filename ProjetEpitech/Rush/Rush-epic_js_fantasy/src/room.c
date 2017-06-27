/*
** room.c for epic_rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 22:01:24 2014 daniel_d
** Last update Sat May 10 22:03:05 2014 daniel_d
*/

int     verif_param_room(t_verifg *v, t_roomg *r, int lap)
{
  int   i;

  i = 0;
  while (i <= lap)
    {
      if (strcmp(v->tab[lap], r->name) != 1)
        return (-1);
      i++;
    }
  return (0);
}



t_roomg *init_room(t_roomg *r)
{
  r->name = strdup("name");
  r->adv = strdup("adv");
  r->tab_connection = strdup("tab_connection");
  r->tab_monster = strdup("tab_monster");
  return (r);
}

int     room(int fd, t_roomg *r)
{
  int   retour_val;
  int   *verif;

  if ((verif = malloc(sizeof(verif) * 6)) == NULL)
    return (-1);
  verif[0] = add_in_file(fd, ROOM, NULL, 0);
  verif[1] = add_in_file(fd, NAME, r->name, 0);
  verif[2] = add_in_file(fd, ADV, r->adv, 0);
  verif[3] = add_in_file(fd, TAB_CONNECTION, r->tab_connection, 0);
  verif[4] = add_in_file(fd, TAB_MONSTER, r->tab_monster, 0);
  verif[5] = add_in_file(fd, SPE_SECTION, NULL, 1);
  retour_val = resum_error(verif, 5);
  free(verif);
  return (retour_val);
}

int     remp_room(int fd)
{
  t_roomg       *r;
  int   laps;
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

