/*
** my_check_buff_for_alias.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/exec_alias/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 28 14:36:45 2014 bouchard alexandre
** Last update Mon May 19 16:15:55 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

char	*my_alias_in_buff(int i, char **tab, char *buff)
{
  char	*index;
  char	*indextmp;
  char	*bufftmp;
  
    if ((index = malloc(sizeof(*index) * (i + 1))) == NULL)
    return (NULL);
  index[i] = '\0';
  while (--i >= 0)
    index[i] = 48;
  indextmp = "1";
  bufftmp = my_put_alias_in_buff(buff, tab, index, indextmp);
  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab);
  free (buff);
  return (bufftmp);
}

char	*my_alias(char *buff)
{
  char	**tab;
  char	*line;
  int	i;
  int	fd;

  i = 0;
  if ((tab = malloc(sizeof(*tab) * 1)) == NULL)
    return (NULL);
  tab[0] = NULL;
  fd = open("tmp.sh", O_RDONLY);
  while ((line = my_get_nextline(fd)) != NULL)
    {
      ++i;
      tab = my_realloc_tab(tab, line);
    }
  buff = my_alias_in_buff(i, tab, buff);
  return (buff);
}
