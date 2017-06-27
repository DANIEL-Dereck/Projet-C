/*
** get_next_line.c for get_next_line in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 15:41:37 2014 marrec_k
** Last update Sun May 25 15:06:27 2014 daniel_d
*/

#include <stdlib.h>
#include <unistd.h>
#include "boogle.h"

char	*my_add_char(char *str, char c)
{
  char	*new;
  int	len;
  int	i;

  len = my_strlen(str);
  if (!(new = malloc(sizeof(*new) * (len + 2))))
    {
      my_puterror("Malloc failed\n", 1);
      return (NULL);
    }
  i = 0;
  while (str && str[i])
    {
      new[i] = str[i];
      i += 1;
    }
  new[i] = c;
  new[i + 1] = 0;
  if (str)
    free(str);
  return (new);
}

char	*get_next_line(int fd)
{
  char	*str;
  char	c;

  str = NULL;
  while (read(fd, &c, 1) && c != '\n')
    {
      if (!(str = my_add_char(str, c)))
	return (NULL);
    }
  return (str);
}
