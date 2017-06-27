/*
** time_calc.c for my_tar in /home/bertho_d/rendu/rush_my_tar
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sun Dec  1 21:24:52 2013 bertho_d
** Last update Sun Dec  1 21:44:34 2013 bertho_d
*/

#include <stdlib.h>
#include "my.h"

void	calc_years_months(int *days, int *months, int *years)
{
  int	leap;
  char	*months_duration;

  leap = (((*years % 4 == 0 && *years % 100 != 0)
	       || *years % 400 == 0) && *days > 365);
  while (*days >= 365 + leap)
    {
      (*days) -= 365 + leap;
      (*years)++;
      leap = (((*years % 4 == 0 && *years % 100 != 0)
	       || *years % 400 == 0) && *days > 365);
    }
  months_duration = my_strdup("303232332323");
  months_duration[1] += leap;
  while (*days >= (28 + months_duration[*months] - '0'))
    {
      *days -= (28 + months_duration[*months] - '0');
      (*months)++;
    }
  free(months_duration);
}

void	disp_date(int time)
{
  int	divs[5];

  divs[0] = time / 60;
  divs[1] = 1 + divs[0] / 60;
  divs[2] = divs[1] / 24;
  divs[3] = 0;
  divs[4] = 1970;
  calc_years_months(&divs[2], &divs[3], &divs[4]);
  divs[0] %= 60;
  divs[1] = divs[1] % 24;
  divs[2] += 1;
  divs[3] += 1;
  my_printf("%.4d-%.2d-%.2d %.2d:%.2d ", divs[4],
	    divs[3], divs[2], divs[1], divs[0]);
}

void		disp_mode(int mode)
{
  int		i;
  int		j;

  i = 0;
  while (i < 3)
    {
      j = 0;
      while (j < 3)
	{
	  if ((mode >> ((2 - i) * 3)) & (1 << (2 - j)))
	    my_putchar(*("rwx" + j));
	  else
	    my_putchar('-');
	  j += 1;
	}
      i += 1;
    }
  my_putchar(' ');
}
