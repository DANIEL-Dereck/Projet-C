/*
** my_display_engine.c for  in /home/le-coa_m/rendu/MUL_2013_wolf3d/src
**
** Made by le-coa_m
** Login   <le-coa_m@epitech.net>
**
** Started on  Sun Jan 12 13:02:42 2014 le-coa_m
** Last update Sun Jun  8 23:01:25 2014 daniel_d
*/

#include "my.h"
#include "rtv1.h"

void	display_time(int bool, int flag, int waiting)
{
  static int	tmp;
  static int	milisecond;
  static int	second;
  static int	minutes;
  static int	hours;

  if (flag == 0)
    tmp++;
  if (bool == 1)
    {
      tmp = tmp / waiting;
      while (tmp >= 0)
      	{
	  (milisecond == 1000) ? ((second += 1), (milisecond = 0)) :
	    (milisecond += 1);
	  (second == 60) ? ((milisecond += 1), (second = 0)) : (milisecond += 1);
	  (minutes == 60) ? ((hours += 1), (minutes = 0)) : (milisecond += 1);
      	  tmp--;
      	}
      my_printf("\nCalul time: %dh %dmin %dsec %dmilisec\n",
		hours, minutes, second, milisecond);
    }
}

void    display_loading(char *prog_name)
{
  int           waiting;
  static int    loading;
  static int    display;

  waiting = ((WIN_Y * WIN_X) / 100) - 15;
  if (loading == waiting && display <= 100 && DEBUG_MODE == 1)
    {
      display_time(0, 0, waiting);
      my_printf("%sLoading %d %%\n", CLEAN, display++);
      loading = 5;
    }
  else if (display == 100 && DEBUG_MODE == 1)
    {
      my_printf("Loading 100 %%\n");
      my_printf("%s", CLEAN);
      my_printf("\033[0;32m==> The %s is fully loaded ! <==\033[0m",
		prog_name);
      display = 101;
      display_time(1, 1, waiting);
    }
  else
    {
      loading += 1;
      display_time(0, 0, waiting);
    }
}
