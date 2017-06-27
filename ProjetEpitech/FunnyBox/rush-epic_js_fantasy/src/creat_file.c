/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Sat May 10 17:27:47 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "epic_editor.h"

int	remp_file(int fd, char **tab)
{
  remp_header(fd);
  if (write(fd, PASS, 5) == -1)
    return (-1);
  remp_champion(fd);
  if (write(fd, PASS, 5) == -1)
    return (-1);
  remp_monster(fd);
  if (write(fd, PASS, 5) == -1)
    return (-1);
  remp_room(fd);
  printf("Name of the game : %s\n", tab[1]);
  return (0);
}

int	creat_file(char *name, char **tab)
{
  int	fd;

  if (name == NULL)
    return (EXIT_FAILURE);
  if ((fd = open(name , O_CREAT | O_RDWR | O_TRUNC ,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (EXIT_FAILURE);
  remp_file(fd, tab);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac < 2)
    {
      printf("%s [name]\n", av[0]);
      return (-1);
    }
  creat_file(av[1], av);
  return (0);
}
