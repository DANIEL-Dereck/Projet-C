/*
** get_next_line.c for get_next_line in /home/julien_t/rendu/CPE_2013_getnextline/CPE_2013_getnextline
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sun Nov 24 16:17:18 2013 julien_t
** Last update Wed Feb  5 16:46:06 2014 julien_t
*/

#include <unistd.h>
#include <stdlib.h>

char	*my_get_next_line(int fd)
{
  char	*str;
  char	*buf;
  int	i;

  i = 0;
  str = malloc(sizeof(*str));
  buf = malloc(sizeof(*buf) * 1);
  while (buf[0] != '\n' && read(fd, buf, 1) != 0)
    {
      str = realloc(str, sizeof(*str) * (i + 1));
      if (buf[0] != '\n')
	str[i] = buf[0];
      i = i + 1;
    }
  if (i == 0)
    return (0);
  str[i] = '\0';
  return (str);
}
