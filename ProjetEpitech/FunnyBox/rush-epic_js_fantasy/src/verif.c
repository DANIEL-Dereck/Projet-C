/*
** verif.c for verif in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 20:58:55 2014 daniel_d
** Last update Sat May 10 21:12:41 2014 daniel_d
*/

int	verif_param_champion(t_verifg *v, t_championg *c, int lap)
{
  int	i;

  i = 0;
  while (i <= lap)
    {
      if (strcmp(v->tab[lap], c->name) != 1)
	return (-1);
      i++;
    }
  return (0);
}

int	verif_param_monster(t_verifg *v, t_monster *m, int lap)
{
  int	i;

  i = 0;
  while (i <= lap)
    {
      if (strcmp(v->tab[lap], m->type) != 1)
	return (-1);
      i++;
    }
  return (0);
}

int	verif_param_room(t_verifg *v, t_roomg *r, int lap)
{
  int	i;

  i = 0;
  while (i <= lap)
    {
      if (strcmp(v->tab[lap], r->name) != 1)
	return (-1);
      i++;
    }
  return (0);
}
