/*
** my_str_alloc.c for libmy in /home/bertho_d/rendu/lib
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Oct 12 17:55:35 2013 bertho_d
** Last update Thu Nov 21 07:46:28 2013 bertho_d
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  if (!src)
    return (NULL);
  i = 0;
  while (src[i++]);
  if (!(dest = malloc(i * sizeof(char))))
    return (NULL);
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strcat_alloc(char *dest, char *src)
{
  int	i;
  int	len_dest;
  int	len_src;
  char	*new_str;

  if (!dest)
    return (my_strdup(src));
  if (!src)
    return (my_strdup(dest));
  len_dest = -1;
  while (dest[++len_dest]);
  len_src = -1;
  while (src[++len_src]);
  if (!(new_str = malloc((len_src + len_dest + 1) * sizeof(char))))
    return (NULL);
  i = 0;
  while (i < (len_src + len_dest))
    {
      new_str[i] = ((i < len_dest) ? dest[i] : src[i - len_dest]);
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}
