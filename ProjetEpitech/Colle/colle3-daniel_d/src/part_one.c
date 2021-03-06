/*
** part_one.c for text_count in /home/even_d/rendu/colle3-daniel_d/src
**
** Made by even_d
** Login   <even_d@epitech.net>
**
** Started on  Thu May 15 19:14:28 2014 even_d
** Last update Thu May 15 20:40:28 2014 even_d
*/

#include <stdlib.h>

#include "text.h"

int	*my_strcatint(int *tab, int nb)
{
  int	*dest;
  int	i;

  i = 0;
  if (tab == NULL)
    {
      if ((dest = malloc(sizeof(*dest) * 2)) == NULL)
	return (NULL);
      dest[0] = nb;
      dest[1] = -1;
      return (dest);
    }
  while (tab[i] != -1)
    i += 1;
  if ((dest = malloc(sizeof(*dest) * (i + 2))) == NULL)
    return (NULL);
  i = -1;
  while (tab[++i] != -1)
    dest[i] = tab[i];
  free(tab);
  dest[i] = nb;
  dest[++i] = -1;
  return (dest);
}

int	my_count_letter(char c, t_core *core)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  if (core->test != NULL)
    {
      while (core->test[i] != '\0' && core->test[i] != c)
	i++;
      if (core->test[i] != '\0')
	return (0);
      i = 0;
    }
  while (core->str[i] != '\0')
    {
      if (core->str[i] == c)
	count += 1;
      i += 1;
    }
  return (count);
}

int	my_check_letter(char c, char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (EXIT_SUCCESS);
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (EXIT_FAILURE);
      i += 1;
    }
  return (EXIT_SUCCESS);
}

void	aff_result(char *str, int *count)
{
  int	i;

  i = 0;
  if (str == NULL || count == NULL)
    return;
  while (str[i] != '\0')
    {
      if (count[i] > 0)
	{
	  my_putchar(str[i]);
	  my_putchar(':');
	  my_put_nbr(count[i]);
	  my_putchar('\n');
	}
      i += 1;
    }
}

void	part_one(char *str)
{
  t_core	core;
  int	i;
  int	ret;

  i = 0;
  core.str = str;
  core.test = NULL;
  core.count = NULL;
  while (core.str[i] != '\0')
    {
      if ((my_check_letter(core.str[i], core.test)) != EXIT_FAILURE)
	{
	  ret = my_count_letter(str[i], &core);
	  if (ret != 0)
	    core.count = my_strcatint(core.count, ret);
	  core.test = my_strcat(core.test, core.str[i]);
	  i += 1;
	}
      else
	i += 1;
    }
  aff_result(core.test, core.count);
}
