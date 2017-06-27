/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Wed Jan  8 11:26:02 2014 daniel_d
*/

#include <math.h>
#include "../Lib/include/intersection.h"
#include "../Lib/include/my.h"

int main(int ac, char **av)
{
  if (ac != 9)
    {
      my_usage();
      return (0);
    }
  my_inter(av);
  return (0);
}
