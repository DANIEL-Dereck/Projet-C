/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Fri Jun 27 02:17:34 2014 daniel_d
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "famille.h"
#include "my.h"

char	*take_name(char *str)
{
  int	s;
  int	i;
  char	*dest;
  int	a;

  a = my_strlen(str);
  i = 0;
  while (str[a] != '/' && a > 0)
    {
      a--;
      i++;
    }
  s = i;
  a++;
  if ((dest = malloc(sizeof(*dest) * i)) == NULL)
    return (NULL);
  i = 0;
  while (s > i)
    dest[i++] = str[a++];
  return (dest);
}

int	famille_bis(char *name, struct dirent *dirent)
{
  int	fd;
  char	*str;
  char	*dest;
  DIR	*dir;

  if ((str = malloc(sizeof(*str))) == NULL)
    return (-1);
  my_printf("%s\n", name);
  while ((dir = opendir(name)) != NULL)
    {
      while ((dirent = readdir(dir)) != NULL)
	{
	  if ((my_strcmp(dirent->d_name, "..") != 0) &&
	      (my_strcmp(dirent->d_name, ".") != 0))
	    {
	      str = strcat(name, "/");
	      if ((str = strcat(str, dirent->d_name)) == NULL)
		return (-1);
	      my_printf("%s\n", str);
	      if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	      else
		while ((dest = get_next_line(fd)) != NULL)
		  my_printf("%s (%s)\n", take_name(str), dest);
	      close(fd);
	    }
	}
    }
  closedir(dir);
  if (famille(str) == -1)
    return (-1);
  return (0);
}

int	famille(char *name)
{
  char	*tmp;
  DIR	*dirp;
  struct dirent *dirent;

  if ((dirp = opendir(name)) == NULL)
    return (-1);
  if ((dirent = readdir(dirp)) != NULL)
    {
      if ((my_strcmp(dirent->d_name, "..") != 0) &&
	  (my_strcmp(dirent->d_name, ".") != 0))
	{
	  if ((tmp = strcat(name, dirent->d_name)) == NULL)
	    return (-1);
	  if (famille_bis(tmp, dirent) == 0)
	    return (-1);
	}
    }
  else
    return (-1);
  closedir(dirp);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac <= 1)
    {
      my_printf("USAGE : %s [famille]\n", av[0]);
      return (-1);
    }
  famille(av[1]);
  return (0);
}
