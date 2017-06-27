/*
** my_str_cpy.c for mystrcpy in /home/daniel_d/rendu/assembleur/asmjv/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Apr 13 21:01:20 2014 daniel_d
** Last update Sun Apr 13 21:01:50 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>

char    *my_str_cpy(char *str1, char *str2)
{
  int i;

  i = 0;
  while (str1[i] != '\0')
    i = i + 1;
  str2 = malloc(sizeof(*str2) * i);
  i = 0;
  while (str1[i] != '\0')
    {
      str2[i] = str1[i];
      i = i + 1;
    }
  return (str2);
}
