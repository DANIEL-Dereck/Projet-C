/*
** my_input.c for libmy in /home/bertho_d/rendu/lib/my/my_io
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Mon Nov 18 18:05:40 2013 bertho_d
** Last update Sun Dec  1 02:46:16 2013 bertho_d
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_defines.h"

static char	*concat_buff(char *buff, char *read_buff, int len)
{
  char	*new_buff;

  read_buff[len] = '\0';
  new_buff = my_strcat_alloc(buff, read_buff);
  free(read_buff);
  if (buff)
    free(buff);
  return (new_buff);
}

char		*get_next_line(const int fd)
{
  static char	*buff;
  char		*temp;
  char		*line;
  int		pos;

  if ((pos = my_find_char('\n', buff)) == -1)
    {
      if (!(temp = malloc((GNL_READ_SIZE + 1) * sizeof(char))))
	return (NULL);
      if ((pos = read(fd, temp, GNL_READ_SIZE)) < 1)
	{
	  free(temp);
	  line = buff;
	  buff = NULL;
	  return (line);
	}
      buff = concat_buff(buff, temp, pos);
      return (get_next_line(fd));
    }
  buff[pos] = '\0';
  line = buff;
  buff = my_strdup(buff + pos + 1);
  return (line);
}
