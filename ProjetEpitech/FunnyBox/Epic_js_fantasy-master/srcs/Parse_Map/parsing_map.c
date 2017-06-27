/*
** parsing_map.c for rush in /home/cordon_b/rendu/rush2
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Sat May 10 09:13:27 2014 cordon_b
** Last update Sun May 11 01:06:12 2014 cordon_b
*/

#include "rush.h"

void	show_list(t_global *global)
{
  t_header	*tmp;
  t_champ	*tmp2;
  t_monster	*tmp3;

  tmp = global->header;
  printf("NAME = [%s] START = [%s] END = [%s] MAGIC-NUMBER = [%d] \n", tmp->name, tmp->start, tmp->end, tmp->magic_number);
  tmp2 = global->champ;
  while (tmp2 != NULL)
    {
      printf("NAME = [%s] TYPE = [%s] HEALTH = [%d] SPEED = [%d] SPE = [%d] DEG = [%d] WEP = [%s] ARM = [%s] \n", tmp2->name, tmp2->type, tmp2->health, tmp2->speed, tmp2->spe, tmp2->deg, tmp2->weapon, tmp2->armor);
      tmp2 = tmp2->next;
    }
  tmp3 = global->monster;
  while (tmp3 != NULL)
    {
      printf("TYPE = %s ", tmp3->type);
      printf("H = %d ", tmp3->health);
      printf("SPEED = %d ", tmp3->speed);
      printf("SPE = %d ", tmp3->spe);
      printf("DEG = %d ", tmp3->deg);
      printf("WP = %s ", tmp3->weapon);
      printf("ARM = %s\n", tmp3->armor);
      tmp3 = tmp3->next;
    }
}

int	recup_type(char *str)
{
  char	*tmp;
  int	i;

  i = 0;
  if ((tmp = malloc(5 * sizeof(*tmp))) == NULL)
    return (EXIT_FAILURE);
  while (str[i] && i < 4)
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  if (strcmp(tmp, "OxOD") == 0)
    return (1);
  else if (strcmp(tmp, "OxOC") == 0)
    return (2);
  else if (strcmp(tmp, "OxOE") == 0)
    return (3);
  else if (strcmp(tmp, "OxOF") == 0)
    return (4);
  return (5);
}

void	init_value(t_global *global)
{
  global->champ = NULL;
  global->monster = NULL;
  global->link = NULL;
}

int	my_open(char *str, int *incr, int ac)
{
  int	fd;

  fd = open(str, O_RDONLY);
  *incr = 0;
  if (ac != 2 || fd == -1)
    exit(write(2, "ERROR BAD ARGV \n", 16));
  return (fd);
}

int	main(int ac, char **av)
{
  char	*s;
  int	fd;
  int	incr;
  t_global	*global;

  if ((global = malloc(sizeof(*global))) == NULL)
    return (write(2, "ERROR MALLOC \n", 14));
  init_value(global);
  fd = my_open(av[1], &incr, ac);
  while ((s = get_next_line(fd)) != NULL)
    {
      if (incr == 0)
	{
	  if ((fill_the_list(global, s, incr)) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else
	{
	  incr = recup_type(s);
	  if ((fill_the_list(global, &s[5], incr)) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      free(s);
    }
  show_list(global);
  //show map
  return (EXIT_SUCCESS);
}
