/*
** my_usage.c for 103 in /home/daniel_d/rendu/103architecte
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Dec  9 15:25:54 2013 daniel_d
** Last update Wed Dec 18 10:39:15 2013 daniel_d
*/

#include "../Lib/include/my.h"

int	my_usage()
{
  my_printf("Usage: 2 coordonnées du point à déplacer (x , y).\n");
  my_printf("translation suivant un vecteur de coordonnées (i, j) : T i j.\n");
  my_printf("homothétie de centre O et de rapports m suivant (Ox) et n suivant (Oy) : H m n.\n");
  my_printf("rotation de centre O et d’angle α degrés : R α.\n");
  my_printf("symétrie par rapport à un axe passant par O incliné de α degrés : S α.\n");
  my_printf("\n\t Exemple :./103architecte 1 2 T 2 3 H 1 -2 R 45 S 30\n");
  return (0);
}
