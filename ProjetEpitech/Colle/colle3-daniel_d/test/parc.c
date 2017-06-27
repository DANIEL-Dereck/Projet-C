/*
** parc.c for parc in /home/daniel_d/colle3-daniel_d/test
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu May 15 20:04:52 2014 daniel_d
** Last update Thu May 15 21:34:17 2014 daniel_d
*/

int	check_on_off(char *str)
{
  int	i;

  i = 0;
  if (str[0] != '-')
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == '=')
	{
	  if (str[i + 1] == 'o' && str[i + 2] == 'f' && str[i + 3] == 'f' &&
	      str[i + 4] == '\0')
	    return (OFF);
	  else if (str[i + 1] == 'o' && str[i + 2] == 'n' && str[i + 3] == '\0')
	    return (ON);
	}
      i++;
    }
  return (ON);
}

int	**set_tab(int **binary_tab)
{
  int	i;

  i = 0;
  if ((binary_tab = malloc(sizeof(**tab) * 2)) == NULL)
    return (NULL);
  while (i < 2)
    {
      if ((binary_tab[i] = malloc(sizeof(*tab) * 5)) == NULL)
	return (NULL);
      i++;
    }
  tab[0][0] = T;
  tab[1][0] = 0;
  tab[0][1] = R;
  tab[1][1] = 0;
  tab[0][2] = REVERSE;
  tab[1][2] = 0;
  tab[0][3] = FULLSTAT;
  tab[1][3] = 0;
  tab[0][4] = ON_THE_FLY;
  tab[1][4] = 0;
  return (tab);
}

int	check_optn(char *str)
{
  if (my_strcmp("-t", str) == 0 || my_strcmp("-t=on", str) == 0)
    return (T);
  else if (my_strcmp("-r", str) == 0 || my_strcmp("-r=on", str) == 0)
    return (R);
  else if (my_strcmp("-reverse", str) == 0 ||
	   my_strcmp("-reverse=on", str) == 0)
    return (REVERSE);
  else if (my_strcmp("-fullstat", str) == 0 ||
	   my_strcmp("-fullstat=on", str) == 0)
    return (FULLSTAT);
  else if (my_strcmp("-on_the_fly", str) == 0 ||
	   my_strcmp("-on_the_fly=on", str) == 0)
    return (ON_THE_FLY);
  else
    return (0);
}

t_core	remp_optn(t_core core, int optn, int r, char *av)
{
  if (optn = T && r == 1)
    core.flags[1][0] = 1;
  else if (optn = R && r == 1)
    core.flags[1][1] = 1;
  else if (optn = REVERSE && r == 1)
    core.flags[1][2] = 1;
  else if (optn = FULLSTAT && r == 1)
    core.flags[1][3] = 1;
  else if (optn = ON_THE_FLY && r == 1)
    core.flags[1][4] = 1;
  else if (core.av1 == NULL)
    core.av1 = av;
  else if (core.av2 == NULL)
    core.av2 = av;
  return (core);
}

t_core	check_option(char **av, int ac)
{
  t_core	core;
  int	r;
  int	i;
  int	optn;

  i = 1;
  optn = 0;
  core.flags = set_tab(core.flags);
  core.av1 = NULL;
  core.av2 = NULL;
  while (i < ac)
    {
      r = check_on_off(av[i]);
      optn = check_optn(av[i]);
      core = remp_optn(core, optn, r, av[i]);
      i++;
    }
  return (core);
}
