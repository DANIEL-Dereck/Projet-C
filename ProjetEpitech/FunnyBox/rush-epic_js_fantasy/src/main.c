/*
** main.c for epic_rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 22:05:32 2014 daniel_d
** Last update Sat May 10 22:07:18 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "epic_editor.h"

int     main(int ac, char **av)
{
  if (ac < 2)
    {
      printf("%s [name]\n", av[0]);
      return (-1);
    }
  creat_file(av[1], av);
  return (0);
}
