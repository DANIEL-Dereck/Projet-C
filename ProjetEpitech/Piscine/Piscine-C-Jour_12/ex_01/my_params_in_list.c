/*
** my_params_in_list.c for my_params_in_list.c in /home/daniel_d/rendu/Piscine-C-Jour_12
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Oct 22 08:44:50 2013 daniel_d
** Last update Wed Oct 23 15:16:04 2013 daniel_d
*/

#include <stdlib.h>
#include "../../Piscine-C-include/mylist.h"

}

void	my_show_list(struct s_list *list)
{
  struct s_list *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp -> data);
      my_putchar('\n');
      tmp = tmp -> next;
    }
}

int	my_put_in_list(struct s_list **list, char **arg)
{
  struct s_list *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem -> data = *arg;
  elem -> next = *list;
  *list = elem;
}

t_list my_params_in_list(int ac, char **av)
{
  struct s_list *list;

  list = NULL;

  av = av + 1;
  while (ac > 1)
    {
      my_put_in_list(&list, av);
      ac = ac - 1;
      av = av + 1;
    }
  my_show_list(list);
 }

