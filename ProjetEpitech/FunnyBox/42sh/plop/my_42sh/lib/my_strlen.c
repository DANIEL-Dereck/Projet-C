/*
** my_strlen.c for int my_strlen(char *str) in /home/boucha_q/rendu/Piscine-C-Jour_04
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Thu Oct  3 15:23:12 2013 boucha_q
** Last update Thu Apr 24 15:05:51 2014 bouchard alexandre
*/

#include <unistd.h>

int     my_strlen(char *str)
{
  int	n;

  n = -1;
  if (str == NULL)
    return (0);
  while (str[++n] != '\0');
  return (n);
}
