/*
** question.c for rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 19:24:57 2014 daniel_d
** Last update Sat May 10 19:37:02 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	question_prime(char *str, int min, int max)
{
  char	buffer[1024];
  int	result;
  int	r;

  printf("enter number of %s in %d and %d pleaz ?\n", str, min, max);
  while ((r = read(0, buffer, 1025)) != -1)
    {
      result = atoi(buffer);
      if (result > max || result < min)
	printf("ERROR : invalid number\n");
      else
	return (result);
      printf("enter number of %s in %d and %d ?\n", str, min, max);
    }
  return (-1);
}
