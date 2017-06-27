/*
** utils.c for my_tar in /home/bertho_d/rendu/rush_my_tar
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Nov 30 09:28:52 2013 bertho_d
** Last update Sun Dec  1 19:04:19 2013 bertho_d
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_tar.h"

void	copy_n_bytes(char *dest, char *src, int n)
{
  while (n > 0)
    {
      n -= 1;
      dest[n] = src[n];
    }
}

int	write_n_chars(int fd, char c, int len)
{
  while (len > 0)
    {
      write(fd, &c, 1);
      len -= 1;
    }
  return (0);
}

int	get_permissions(t_header *header)
{
  int	perms;

  if (!header)
    return (0);
  perms = my_getnbr_base(header->mode, "01234567");
  perms %= 512;
  return (perms);
}

char	*add_slash(char *str)
{
  char	*result;
  int	len;

  if (!str)
    return (NULL);
  len = my_strlen(str);
  if (str[len - 1] == '/')
    return (my_strdup(str));
  result = my_strcat_alloc(str, "/");
  free(str);
  return (result);
}

char	*get_file_content(int fd, int *len)
{
  char	*temp;
  char	*content;
  char	buffer[READ_SIZE];
  int	ret_val;

  if (!len)
    return (NULL);
  content = NULL;
  *len = 0;
  while ((ret_val = read(fd, buffer, READ_SIZE)))
    {
      if (ret_val == -1)
	return (NULL);
      *len += ret_val;
      temp = content;
      if (!(content = malloc((*len) * sizeof(char))))
	return (NULL);
      copy_n_bytes(content, temp, *len - ret_val);
      copy_n_bytes(content + *len - ret_val, buffer, ret_val);
      if (temp)
	free(temp);
    }
  if (*len == 0)
    *len = -1;
  return (content);
}

