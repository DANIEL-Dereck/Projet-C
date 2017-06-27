/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Mon Jan 20 14:09:09 2014 daniel_d
*/

#include "tore.h"
#include "my.h"

int main(int ac, char **av)
{
  if (ac != 8)
    {
      my_usage(av);
      return (0);
    }
  toretue(av);
  return (0);
}
