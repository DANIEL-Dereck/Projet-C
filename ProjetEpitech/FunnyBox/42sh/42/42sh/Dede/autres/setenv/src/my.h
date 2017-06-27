/*
** my.h for my.h in /home/aubry_f/rendu/42sh/setenv
** 
** Made by aubry_f
** Login   <aubry_f@epitech.net>
** 
** Started on  Wed Apr 23 20:18:07 2014 aubry_f
** Last update Fri May 16 16:02:34 2014 aubry_f
*/

#ifndef MY_H_
#define MY_H_

typedef struct		s_list
{
  char		*envir;
  struct s_list	*next;
}t_list;

void	show_list(t_list **list);
int	put_tail_list(t_list **list, char *envir);
char    *my_strcat(char *dest, char *src);
char    *my_strcpy(char *dest, char *src);
int     my_getnbr(char *str);
int     my_strlen(char *str);

#endif
