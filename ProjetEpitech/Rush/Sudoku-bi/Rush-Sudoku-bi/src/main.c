/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Sat Mar  1 09:40:48 2014 daniel_d
*/

#include "sudoku.h"
#include "my.h"

int main(int ac, char **av)
{
  if (ac <= 1)
    {
      my_printf("Usage : %s [map] ...\n", av[0]);
      return (0);
    }
  sudokumain(av);
  return (0);
}
