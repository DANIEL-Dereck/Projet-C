/*
** my_strdup.c for my_strdup.c in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 13:56:09 2013 julien_t                               
** Last update Wed Feb  5 15:53:58 2014 julien_t
*/

#include <stdlib.h>

char    *my_strdup(char *str)
{
  char	*dest;

  dest = malloc(sizeof(*dest) * (my_strlen(str) + 1));
  my_strcpy(dest, str);
  dest[my_strlen(str)] = 0;
  return (dest);
}
