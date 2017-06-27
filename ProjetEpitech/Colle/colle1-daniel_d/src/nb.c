/*
** nb.c for colle1 in /home/thepatriot/rendu/colle1
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Tue Apr 29 15:01:45 2014 bertho_d
** Last update Tue Apr 29 16:44:29 2014 bertho_d
*/

#include <stdlib.h>
#include "pi.h"

int		nb_get_val(t_nb *nb, char *nb_ptr)
{
  if (!nb || nb_ptr > nb->end || nb_ptr < nb->val)
    return (0);
  return (*nb_ptr - '0');
}

char		*nb_get_dec_ptr(t_nb *nb)
{
  if (!nb || !(nb->val))
    return (NULL);
  return (nb->val + nb->int_part_size);
}

void		disp_nb(t_nb *nb)
{
  int		i;
  char		*ptr;

  i = -1;
  while (++i < nb->int_part_size && nb->val[i] == '0');
  if ((nb->int_part_size - i) > 0)
    write(1, (nb->val + i), (nb->int_part_size - i));
  else
    write(1, "0", 1);
  ptr = nb->val + nb->int_part_size;
  if (ptr <= nb->end)
    {
      write(1, ",", 1);
      write(1, ptr, (nb->end - ptr) + 1);
    }
  write(1, "\n", 1);
}

int		check_nb(char *val)
{
  int		i;
  int		pos;

  if (!val)
    return (-1);
  pos = -1;
  i = -1;
  while (val[++i])
    {
      if (val[i] == ',' && pos == -1)
	pos = i;
      else if (val[i] == ',')
	return (-1);
      else if (val[i] > '9' || val[i] < '0')
	return (-1);
    }
  if (pos == -1)
    return (i);
  return (pos);
}

int		init_nb(t_nb *nb, char *val)
{
  char		*ptr;

  nb->val = val;
  if ((nb->int_part_size = check_nb(val)) < 1)
    return (-1);
  ptr = nb->val + nb->int_part_size;
  while (*ptr)
    {
      *ptr = *(ptr + 1);
      ptr += 1;
    }
  nb->end = ptr - 1;
  if (*(nb->end) == '\0')
    nb->end -= 1;
  return (0);
}
