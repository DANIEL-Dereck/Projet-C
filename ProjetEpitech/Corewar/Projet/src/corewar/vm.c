/*
** vm.c for vm in /home/daniel_d/rendu/CPE_2014_Corewar/corewar/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr  1 16:37:06 2014 daniel_d
** Last update Sun Apr 13 21:51:29 2014 daniel_d
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int	verif_champion(char *champion)
{
  int	i;

  i = 0;
  while (champion[i] != '\0')
    {
      if (champion[i] == '.')
	if (champion[i + 1] == 'c')
	  if (champion[i + 2] == 'o')
	    if (champion[i + 3] == 'r')
	      if (champion[i + 4] == '\0')
		{
		  my_printf("The champion : \'%s\' is ready\n", champion);
		  return (1);
		}
      i++;
    }
  my_printf("%s is not a corewar executable\n", champion);
  return (FAIL);
}

int     arena(char **champion)
{
  int   cycle;
  int   cycle_to_die;
  int   cycle_delta;

  cycle_to_die = 0;
  cycle = 0;
  cycle_delta = 0;
  my_printf("OK %s\n", champion[0]);
  while (cycle_to_die < CYCLE_TO_DIE)
    {
      while (cycle_delta < NBR_LIVE)
        {
          cycle++;
          cycle_delta++;
        }
      cycle_delta = 0;
    }
  return (0);
}

int	vm_main(char **champion)
{
  arena(champion);
  return (0);
}
