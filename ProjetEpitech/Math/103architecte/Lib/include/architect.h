/*
** 103.h for 103 in /home/daniel_d/rendu/103architecte
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Dec 11 12:41:44 2013 daniel_d
** Last update Mon Dec 16 11:26:03 2013 daniel_d
*/

#ifndef ARCHITECT_H_
# define ARCHITECT_H_

int     my_usage();
float   *translation(float *tab, int param1, int param2);
float   *homothetie(float *tab, int param1, int param2);
float   *rotation(float *tab, int angle);
float   *symetrie(float *tab, int angle);
float   *my_calc(char **av, float *tab, int *verif);
int     my_aff(char **av, int *verif);
float   *my_coord(float *matrix, int *verif, char **av);
float   *coord_t(float *matrix, int param1, int param2);
float   *coord_h(float *matrix, int param1, int param2);
float   *coord_r(float *matrix, int param);
float   *coord_s(float *matrix, int param);



#endif
