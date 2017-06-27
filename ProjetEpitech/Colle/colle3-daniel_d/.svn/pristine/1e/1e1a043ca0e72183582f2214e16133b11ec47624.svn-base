/*
** my_strcmp.c for strcmp in /home/daniel_d/colle3-daniel_d/lib
**
** Made by daniel_d
** Login   <daniel_d@epitech.net>
**
** Started on  Thu May 15 19:18:45 2014 daniel_d
** Last update Thu May 15 22:19:37 2014 even_d
*/

#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
    i++;
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  return (s1[i] - s2[i]);
}
