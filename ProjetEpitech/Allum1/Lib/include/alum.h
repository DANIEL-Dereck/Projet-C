/*
** alum.h for alum1 in /home/daniel_d/rendu/alum1/Lib/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Feb 10 13:53:32 2014 daniel_d
** Last update Sun Feb 16 22:35:49 2014 daniel_d
*/

#ifndef ALUM_H_
# define ALUM_H_

int	alumain();
int	playerselect();
int	ligneforplay();
int	jcj(char **sapin, int nl);
int	ia(char **sapin, int nl);
char	**sapin(int nl);
int	pipercount(char **tab, int nl);
int	aff_tab(char **sapin, int nl);
int     pipecount(char **tab, int nl);
char    **jcj_play(char **sapin, char *buffer, int nl);
char    **ia_play(char **sapin, char *buffer, int nl);
int     my_count_x_char(char *str, char c);
int     verif(char **sapin, int nl, int j, char *buffer);
int     ia_verif(char **sapin, int nl, int j, char *buffer);
char	*epurestr(char *buffer);
char    *my_concat_str(char *dest, char *src);
char	**iabrain(char **sapin, int nl);

#endif
