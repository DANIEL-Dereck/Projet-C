/*
** tore.h for 105 in /home/daniel_d/rendu/105tore/Lib/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Jan 15 11:51:13 2014 daniel_d
** Last update Wed Jan 22 14:57:21 2014 daniel_d
*/

#ifndef TORE_H_
# define TORE_H_

int	my_usage(char **av);
int	toretue(char **av);
int	equa_aff(char **av);
int	my_bis(char **av);
int	my_newton(char **av);
int	my_sec(char **av);
double	*tabinit(char **av);
double	f(double x, double *tab);
double	derive_f(double x, double *tab);

#endif
