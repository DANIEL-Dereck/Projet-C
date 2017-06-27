/*
** get_nextline.c for get_nextline in /home/jouana_j/rendu/101pong/lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Dec  2 17:02:58 2013 jouana_j
** Last update Sun Dec  8 17:18:39 2013 jouana_j
*/

#include <unistd.h>
#include <stdlib.h>

char	*my_get_nextline(int fd)
{
  char	*str;
  char	*buf;
  int	i;

  i = 0;
  str = malloc(sizeof(*str));
  buf = malloc(sizeof(*buf) * 1);
  while (buf[0] != '\n' && read(fd, buf, 1) != 0)
    {
      str = my_realloc(str, sizeof(*str) * (i + 1));
      if (buf[0] != '\n')
	str[i] = buf[0];
      i = i + 1;
    }
  if (i == 0)
    return 0;
  str[i] = '\0';
  free(buf);
  return (str);
}
