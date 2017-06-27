/*
** init_tab.c for init_tab in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Jun  4 16:33:09 2014 daniel_d
** Last update Sun Jun  8 21:57:36 2014 daniel_d
*/

#include "ray.h"

char    **init_tab_start(char **start)
{
  start[0] = my_strdup(BS_RACINE);
  start[1] = my_strdup(BS_EYE);
  start[2] = my_strdup(BS_OBJ);
  start[3] = my_strdup(BS_ROTATE);
  start[4] = my_strdup(BS_POSITION);
  start[5] = my_strdup(BS_COLOR);
  start[6] = my_strdup(BS_SPOT);
  start[7] = my_strdup(BS_PLAN);
  start[8] = my_strdup(BS_SPHERE);
  start[9] = my_strdup(BS_CONE);
  start[10] = my_strdup(BS_CYLINDRE);
  start[11] = my_strdup(BS_PARA);
  start[12] = NULL;
  return (start);
}

char    **init_tab_end(char **end)
{
  end[0] = my_strdup(BE_RACINE);
  end[1] = my_strdup(BE_EYE);
  end[2] = my_strdup(BE_OBJ);
  end[3] = my_strdup(BE_ROTATE);
  end[4] = my_strdup(BE_POSITION);
  end[5] = my_strdup(BE_COLOR);
  end[6] = my_strdup(BE_SPOT);
  end[7] = my_strdup(BE_PLAN);
  end[8] = my_strdup(BE_SPHERE);
  end[9] = my_strdup(BE_CONE);
  end[10] = my_strdup(BE_CYLINDRE);
  end[11] = my_strdup(BE_PARA);
  end[12] = NULL;
  return (end);
}
