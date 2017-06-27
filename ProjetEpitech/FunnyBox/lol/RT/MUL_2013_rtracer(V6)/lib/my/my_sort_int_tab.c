/*
** my_sort_int_tab.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:35:53 2013 jouana_j
** Last update Thu Nov 14 17:54:32 2013 jouana_j
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;
  int	tmp;

  i = 0;
  while (i < size)
    {
      j = i;
      while (j < size)
	{
	  if (tab[j] < tab[i])
	    {
	      tmp = tab[i];
	      tab[i] = tab[j];
	      tab[j] = tmp;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}
