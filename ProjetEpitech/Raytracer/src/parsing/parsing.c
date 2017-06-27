/*
** parsing.c for parsing in /home/daniel_d/rendu/RT/RT_parseur/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue May 27 08:51:51 2014 daniel_d
** Last update Sun Jun  8 14:19:40 2014 daniel_d
*/

#include "ray.h"

char	**init_map(int fd, char **tab)
{
  char	*str;
  int	i;

  i = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((tab[i] = malloc(sizeof(*tab) * my_allocsize(str))) == NULL)
	return (NULL);
      str = my_epur_str(str);
      if ((tab[i] = my_strcpy(tab[i], str)) == NULL)
	return (NULL);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

int	check_file(char *map)
{
  if (my_strcmpv2(map, FILE) == 0)
    return (0);
  my_printf("ERROR : Bad extention\n");
  return (-1);
}

int	parsing(char *map)
{
  char	*str;
  char	**tab;
  int	i;
  int	fd;

  i = 0;
  if (check_file(map) == -1)
    return (-1);
  if ((fd = open(map, O_RDONLY)) == -1)
    {
      my_printf("ERROR : oepn failure or map invalid\n");
      return (-1);
    }
  while ((str = get_next_line(fd)) != NULL)
    i++;
  close(fd);
  if ((fd = open(map, O_RDONLY)) == -1)
    return (-1);
  if ((tab = malloc(sizeof(tab) * i)) == NULL)
    return (-1);
  if ((tab = init_map(fd, tab)) == NULL)
    return (-1);
  close(fd);
  remp_list(tab);
  return (0);
}
