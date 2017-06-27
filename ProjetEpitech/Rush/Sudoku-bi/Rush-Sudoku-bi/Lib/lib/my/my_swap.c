/*
** my_swap.c for my_swap.c in /home/daniel_d/rendu/Piscine-C-Jour_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Oct  3 08:52:41 2013 daniel_d
** Last update Wed Feb 19 13:34:40 2014 daniel_d
*/

int	my_swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
