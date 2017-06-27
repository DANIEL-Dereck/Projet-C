/*
** utils.c for utils in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 14:18:55 2014 marrec_k
** Last update Wed May 21 14:24:08 2014 marrec_k
*/

#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i += 1;
  return (i);
}

void	my_putstr(char *str)
{
  if (str)
    write(1, str, my_strlen(str));
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (1);
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (1);
      i += 1;
    }
  return (0);
}

char	*my_strdup(char *str)
{
  int	i;
  int	l;
  char	*new;

  i = 0;
  if (!str)
    return (NULL);
  l = my_strlen(str);
  if (!(new = malloc(sizeof(*new) * (l + 1))))
    return (NULL);
  while (str[i])
    {
      new[i] = str[i];
      i += 1;
    }
  new[i] = 0;
  return (new);
}
