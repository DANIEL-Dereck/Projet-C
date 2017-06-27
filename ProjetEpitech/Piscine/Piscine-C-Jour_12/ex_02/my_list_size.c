/*
** my_list_size.c for my_list_size.c in /home/daniel_d/rendu/Piscine-C-Jour_12/ex_02
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Oct 22 17:03:30 2013 daniel_d
** Last update Tue Oct 22 21:15:32 2013 daniel_d
*/

int	my_list_size(t_list *begin)
{
  struct s_list *list;
  int a;

  list = NULL;
  a = 0;
  while (*begin != NULL)
    {
      elem -> next = *list;
      *begin = elem -> next;
      a = a + 1;
    }
  return (a);
}

