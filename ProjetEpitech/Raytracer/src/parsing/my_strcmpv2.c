/*
** my_strcmpv2.c for my_strcmpv2 in /home/daniel_d/rendu/MUL_2013_rtracer/src/parsing
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Jun  8 22:34:30 2014 daniel_d
** Last update Sun Jun  8 22:34:41 2014 daniel_d
*/

#include "ray.h"

int     my_strcmpv2(char *s1, char *s2)
{
  int   i;
  int   l;

  i = 0;
  l = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != '\0' || s2[l] != '\0')
    {
      if (s2[l] == '*')
        {
          l++;
          while (s1[i] != s2[l] && s1[i] != '\0')
            i++;
        }
      else if (s1[i] != s2[l])
        return (-1);
      i++;
      l++;
    }
  if (s1[i] == s2[l])
    return (0);
  else
    return (-1);
}
