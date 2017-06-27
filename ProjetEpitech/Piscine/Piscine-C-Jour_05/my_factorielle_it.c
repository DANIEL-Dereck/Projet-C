/*
** my_factorielle_it.c for my_factorielle_it in /home/daniel_d/rendu/Piscine-C-Jour_05
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Oct  4 09:06:24 2013 daniel_d
** Last update Sun Oct 13 12:56:47 2013 daniel_d
*/

int	my_factorielle_it(int nb)
{

  int result;

  result = nb;

  if( nb < 0 )
    return(0);

  if( nb > 12 )
    return(0);

  if( nb = 0 )
    return(1);

  while( nb > 1 )
    {
      nb = nb - 1;
      result = nb * result;
    }
  return(result);
}
