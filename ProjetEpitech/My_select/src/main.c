/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Sun Jan 19 19:06:27 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "my.h"
#include "select.h"

int main(int ac, char **av)
{
  if (ac == 1)
    {
      my_printf("Usage : %s [list]\n", av[0]);
      return (0);
    }
  selectmain(av);
  return (0);
}
