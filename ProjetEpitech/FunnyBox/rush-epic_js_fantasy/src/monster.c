/*
** monster.c for epic_rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 21:58:56 2014 daniel_d
** Last update Sat May 10 22:01:16 2014 daniel_d
*/

int     verif_param_monster(t_verifg *v, t_monster *m, int lap)
{
  int   i;

  i = 0;
  while (i <= lap)
    {
      if (strcmp(v->tab[lap], m->type) != 1)
        return (-1);
      i++;
    }
  return (0);
}

t_monsterg      *init_monster(t_monsterg *m)
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

int     remp_monster(int fd)
{
  t_monsterg    *m;
  int   laps;
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
