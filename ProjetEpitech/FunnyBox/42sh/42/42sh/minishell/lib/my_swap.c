/*
** my_swap.c for int my_swap(int *a, int *b) in /home/boucha_q/rendu/Piscine-C-Jour_04
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Thu Oct  3 09:31:10 2013 boucha_q
** Last update Fri Oct  4 21:33:07 2013 boucha_q
*/

int	my_swap(int *a , int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;
}
