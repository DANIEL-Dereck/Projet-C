/*
** func.c for func in /home/daniel_d/rendu/rush_funk
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun May 11 04:05:12 2014 daniel_d
** Last update Sun May 11 15:29:47 2014 daniel_d
*/

t_champ	*need_good_champ(t_champ *c, char *name_champ)
{
  while (c->name != NULL)
    {
      if (strcmp(c->name, name_champ) != 0)
	return (c);
      c = c->next;
    }
  return (NULL);
}

t_monster	*need_good_monster(t_monster *m, char *type_monster)
{
  while (m->type != NULL)
    {
      if (strcmp(c->name, type_monster) != 0)
	return (m);
      m = m->next;
    }
  return (NULL);
}

int	check_player(t_champ *c)
{
  if (c->health > 0)
    return (0);
  else
    return (-1);
}

int	check_monster(t_monster *m)
{
  if (m->health > 0)
    return (0);
  else
    return (-1);
}

t_monster	*damage_value(t_champ *c, t_monster *m, char *str)
{
  int	damage;
  char	**tab;

  tab = my_str_to_wordtab(str);
  damage = atoi(tab[1]);
  if (damage <= 0)
    return (NULL);
  c = need_good_champ(c, tab[0]);
  if (check_player(c) == -1)
    return (NULL);
  m = need_good_monster(m, tab[2]);
  if (check_monster(m) == -1)
    return (NULL);
  m->health = m->health - damage;
  printf("%s attacks %s. he lost %dHP\n", tab[0], tab[2], damage);
  if (m->health > 0)
    return (m);
  else
    {
      printf("%s die\n", tab[2]);
      m = delet_maillon(m);
    }
  return (NULL);
}
