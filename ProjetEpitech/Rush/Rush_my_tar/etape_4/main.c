/*
** main.c for test in /home/daniel_d/rendu/Projet_fini/rush_my_tar/etape_4
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Dec  6 10:36:33 2013 daniel_d
** Last update Fri Dec  6 10:37:16 2013 daniel_d
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"

int main(int ac, char **av)
{
  static int fd;
  char *s;

  fd = open(av[1], O_RDONLY);
  while ((s = get_next_line(fd)))
    {
      my_putstr(s);
      free(s);
      my_putchar('\n');
    }
  my_putchar('\n');
  return (0);
}

