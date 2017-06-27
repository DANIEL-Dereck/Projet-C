/*
** champion.c for epic_rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 21:59:10 2014 daniel_d
** Last update Sat May 10 22:00:30 2014 daniel_d
*/

int     verif_param_champion(t_verifg *v, t_championg *c, int lap)
{
  int   i;

  i = 0;
  while (i <= lap)
    {
      if (strcmp(v->tab[lap], c->name) != 1)
        return (-1);
      i++;
    }
  return (0);
}

int     champion(int fd, t_championg *c)
{
  int   retour_val;
  int   *verif;

  if ((verif = malloc(sizeof(verif) * 10)) == NULL)
    return (-1);
  verif[0] = add_in_file(fd, CHAMPION, NULL, 0);
  verif[1] = add_in_file(fd, NAME, c->name, 0);
  verif[2] = add_in_file(fd, TYPE, c->type, 0);
  verif[3] = add_in_file(fd, HP, c->hp, 0);
  verif[4] = add_in_file(fd, SPE, c->spe, 0);
  verif[5] = add_in_file(fd, SPEED, c->speed, 0);
  verif[6] = add_in_file(fd, DEG, c->deg, 0);
  verif[7] = add_in_file(fd, WEAPON, c->weapon, 0);
  verif[8] = add_in_file(fd, ARMOR, c->armor, 0);
  verif[9] = add_in_file(fd, SPE_SECTION, NULL, 1);
  retour_val = resum_error(verif, 9);
  free(verif);
  return (retour_val);
}

t_championg     *init_champion(t_championg *c)
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

int     remp_champion(int fd)
{
  t_championg   *c;
  int   laps;
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
