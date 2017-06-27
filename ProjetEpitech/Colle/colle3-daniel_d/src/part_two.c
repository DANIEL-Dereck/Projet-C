/*
** part_two.c for text_count in /home/even_d/rendu/colle3-daniel_d/src
**
** Made by even_d
** Login   <even_d@epitech.net>
**
** Started on  Thu May 15 20:14:42 2014 even_d
** Last update Thu May 15 22:48:27 2014 even_d
*/

#include <stdlib.h>

#include "text.h"

void    part_two(char *str, char *test)
{
  t_core        core;
  int   i;
  int   ret;

  i = 0;
  core.str = str;
  core.test = NULL;
  core.count = NULL;
  while (test[i] != '\0')
    {
      if ((my_check_letter(test[i], core.test)) != EXIT_FAILURE)
        {
          ret = my_count_letter(test[i], &core);
          if (ret != 0)
            core.count = my_strcatint(core.count, ret);
          core.test = my_strcat(core.test, test[i]);
          i += 1;
        }
      else
        i += 1;
    }
  aff_result(test, core.count);
}
