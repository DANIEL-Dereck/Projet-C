/*
** my_cdbis.c for my_cd in /home/daniel_d/rendu/42/42sh/Dede/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue May 13 11:02:05 2014 daniel_d
** Last update Sun May 25 15:00:06 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

int     aff_directory(char *env, int pos)
{
  pos++;
  while (env[pos] != '\0')
    my_putchar(env[pos++]);
  my_putchar('\n');
  return (0);
}

char    *cpydirec(int l, char *str, char *buffer)
{
  int   i;

  i = 0;
  if ((str = malloc(sizeof(*str) * (my_strlen(buffer) - l) + 1)) == NULL)
    return (NULL);
  while (buffer[l] != '\n' && buffer[l] != '\0')
    {
      str[i] = buffer[l];
      i++;
      l++;
    }
  str[i] = '\0';
  return (str);
}
