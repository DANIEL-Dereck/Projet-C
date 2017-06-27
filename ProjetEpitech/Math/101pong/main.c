/*
** main.c for 101pong in /home/daniel_d/rendu/101pong
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Nov 11 10:55:04 2013 daniel_d
** Last update Tue Nov 19 17:04:35 2013 daniel_d
*/

#include "my.h"
#include "pong.h"

int	main(int argc, char **argv)
{
  if (argc != 8)
    {
      my_putstr("Usage: 1 2 3 4 5 6 7\n");
      my_putstr("1 = l’abscisse de la balle à l’instant t − 1\n");
      my_putstr("2 = l’ordonnée de la balle à l’instant t − 1\n");
      my_putstr("3 = l’altitude de la balle à l’instant t − 1\n");
      my_putstr("4 = l’abscisse de la balle à l’instant t\n");
      my_putstr("5 = l’ordonnée de la balle à l’instant t\n");
      my_putstr("6 = l’altitude de la balle à l’instant t\n");
      my_putstr("7 = un entier strictement positif n\n");
      my_putstr("exemple : ./101pong -5 -2 10 -3 1 9 4\n");
      return (0);
    }
  else
    {
      coorvec(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
      instantk(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
      angleinc(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
    }
  return (0);
}
