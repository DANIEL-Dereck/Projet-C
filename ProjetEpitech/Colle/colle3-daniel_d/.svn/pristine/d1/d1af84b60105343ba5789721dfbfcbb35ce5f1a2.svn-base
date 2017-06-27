/*
** part_three.c for text_count in /home/even_d/rendu/colle3-daniel_d/src
**
** Made by even_d
** Login   <even_d@epitech.net>
**
** Started on  Thu May 15 20:57:28 2014 even_d
** Last update Thu May 15 22:43:38 2014 even_d
*/

#include <stdlib.h>

#include "text.h"

int	my_max(int *count)
{
  int	i;
  int	max;

  while (count[i] != -1)
    {
      if (count[i] > max)
	max = count[i];
      i += 1;
    }
  return (max);
}

void	aff_result_t(char *str, int *count)
{
  int	i;
  int	max;

  max = my_max(count);
  while (max > 0)
    {
      i = 0;
      while (count[i] != -1)
	{
	  if (count[i] == max)
	    {
	      aff_element(str[i], count[i]);
	      my_putchar('\n');
	    }
	  i += 1;
	}
      max -= 1;
    }
}

void	aff_result_r(char *str, int *count)
{
  int	max;
  int	i;
  int	boo;

  max = my_max(count);
  while (max > 0)
    {
      i = 0;
      boo = 0;
      while (count[i] != -1)
	{
	  if (count[i] == max)
	    {
	      aff_element_two(str[i], count[i], boo);
	      boo = 1;
	    }
	  i += 1;
	}
      if (boo == 1)
	my_putchar('\n');
      max -= 1;
    }
}

void	aff_result_option(t_core *core)
{
  int	i;

  i = 0;
  while (i < 5)
    {
      if (core->flags[1][i] == 1)
	{
	  if (i == 0)
	    aff_result_t(core->test, core->count);
	  if (i == 1)
	    aff_result_r(core->test, core->count);
	}
      i += 1;
    }
}

void    part_three(t_core *core)
{
  int   i;
  int   ret;

  i = 0;
  core->str = core->av1;
  core->test = NULL;
  core->count = NULL;
  while (core->av2[i] != '\0')
    {
      if ((my_check_letter(core->av2[i], core->test)) != EXIT_FAILURE)
        {
          ret = my_count_letter(core->av2[i], core);
          if (ret != 0)
            core->count = my_strcatint(core->count, ret);
          core->test = my_strcat(core->test, core->av2[i]);
          i += 1;
        }
      else
        i += 1;
    }
  aff_result_option(core);
}
