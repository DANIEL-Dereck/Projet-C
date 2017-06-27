/*
** my_rev_list.c for my_rev_list.c in /home/daniel_d/rendu/Piscine-C-Jour_12/ex_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Oct 22 21:16:40 2013 daniel_d
** Last update Tue Oct 22 22:14:11 2013 daniel_d
*/

void	my_show_list(struct s_list *list)
{
  struct s_list *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp -> data);
      my_putchar('\n');
      tmp = tmp ->next;
    }
}

int	my_put_in_list(struct s_list **list, char **arg)
{
  struct l_list *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem -> data = *arg;
  elem -> next = *list;
  *list = elem;
}

