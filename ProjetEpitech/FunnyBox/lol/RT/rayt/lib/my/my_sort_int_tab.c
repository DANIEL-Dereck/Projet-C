/*
** my_sort_int_tab.c for my_sort_int_tab in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Fri Oct 18 21:44:36 2013 julien_t
** Last update Fri Oct 25 15:50:51 2013 julien_t
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	sort;
  int	nb;

  nb = 0;
  sort = 0;
  while (sort == 0)
    {
      i = 0;
      sort = 1;
      while ((i + i) < size)
	{
	  if (tab[i] > tab[i + 1])
	    {
	      sort = 0;
	      my_swap(&tab[i], &tab[i + 1]);
	    }
	  i = i + 1;
	}
      nb++;
    }
}
