/*
** text.h for test_count in /home/even_d/rendu/colle3-daniel_d/include
**
** Made by even_d
** Login   <even_d@epitech.net>
**
** Started on  Thu May 15 19:11:07 2014 even_d
** Last update Thu May 15 22:44:10 2014 even_d
*/

#ifndef TEXT_H_
# define TEXT_H_

typedef struct s_core
{
  char	*av1;
  char	*av2;
  int	**flags;
  char	*str;
  char	*test;
  int	*count;
}t_core;

#define T 1
#define	R 2
#define REVERSE 4
#define FULLSTAT 8
#define ON_THE_FLY 16

#define ON 1
#define OFF -1

void	my_putstr(char *);
void	my_putchar(char);
void	my_put_nbr(int);
int	my_strlen(char *);
char	*my_strcat(char *, char);
int	my_strcmp(char *, char *);
int	*my_strcatint(int *, int);
int	my_count_letter(char, t_core *);
int	my_check_letter(char, char *);
void	aff_result(char *, int *);
void	aff_element(char, int);
void	aff_element_two(char, int, int);
void	part_one(char *);
void	part_two(char *, char *);
void	part_three(t_core *);
t_core	check_option(char **, int);
#endif /* !TEXT_H__ */
