/*
** my_swap.c for my_swap in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Fri Oct 18 21:21:11 2013 julien_t
** Last update Fri Oct 18 21:22:52 2013 julien_t
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
