/*
** my_str_alter.c for libmy in /home/bertho_d/rendu/lib
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Oct 12 17:55:48 2013 bertho_d
** Last update Sat Nov  9 19:49:47 2013 bertho_d
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	len;
  char	c;

  if (!str)
    return (str);
  len = my_strlen(str) - 1;
  i = len;
  while (i > (len / 2))
    {
      c = str[len - i];
      str[len - i] = str[i];
      str[i] = c;
      i--;
    }
  return (str);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  if (!dest || !src)
    return (dest);
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  if (!dest || !src || n < 1)
    return (dest);
  i = 0;
  while (i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	len;

  if (!dest || !src)
    return (dest);
  len = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = '\0';
  return (dest);
}

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	len;

  if (!dest || !src || nb == 0)
    return (dest);
  len = my_strlen(dest);
  i = 0;
  while (src[i] && i < nb)
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = '\0';
  return (dest);
}
