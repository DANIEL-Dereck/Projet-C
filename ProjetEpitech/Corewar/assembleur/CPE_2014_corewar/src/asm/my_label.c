/*
** my_label.c for label in /home/daniel_d/rendu/assembleur/asmjv/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Apr 13 21:03:42 2014 daniel_d
** Last update Sun Apr 13 21:04:00 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>

char    *my_label(char *plop)
{
  char *label;
  int i;
  int x;

  x = 0;
  i = 0;
  while (plop[i] != '\0')
    i = i + 1;
  label = malloc(sizeof(*label) * i + 2);
  i = 2;
  while (plop[i] != '\0')
    label[x++] = plop[i++];
  label[x] = ':';
  label[x + 1] = '\0';
  return (label);
}
