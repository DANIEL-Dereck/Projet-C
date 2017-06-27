/*
** select.h for select in /home/daniel_d/rendu/PSU_2013_my_select/Lib/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Jan 18 15:07:43 2014 daniel_d
** Last update Sun Jan 19 19:07:12 2014 daniel_d
*/

#ifndef SELECT_H_
# define SELECT_H_

struct s_prime
{
  char	*word;
  struct s_prime *next;
  struct s_prime *prev;
};

typedef struct s_list
{
  int	size;
  struct s_prime *head;
  struct s_prime *last;
} t_list;

int	selectmain(char **av);
t_list  *list_chain(t_list *chaine);
t_list  *init_chain(t_list *chaine);


#endif
