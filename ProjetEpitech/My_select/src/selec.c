/*
** selec.c for my_select$ in /home/daniel_d/rendu/PSU_2013_my_select/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Jan 18 15:07:04 2014 daniel_d
** Last update Sun Jan 19 22:42:29 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "my.h"
#include "select.h"

t_list	*init_chain(t_list *chaine)
{
  struct s_prime *truc;

  if (chaine != NULL)
    {
      if ((truc = malloc(sizeof(*truc))) == NULL)
	return (0);
      if (chaine->last == NULL)
	{
	  chaine->head = truc;
	  chaine->last = truc;
	  truc->next = NULL;
	  truc->prev = NULL;
	  chaine->size++;
	}
      else
	{
	  truc->prev = chaine->last;
	  chaine->last->next = truc;
	  truc->next = NULL;
	  chaine->last = truc;
	  chaine->size++;
	}
    }
  return (chaine);
}

t_list	*list_chain(t_list *chaine)
{
  if (chaine == NULL)
    {
      if ((chaine = malloc(sizeof(*chaine))) == NULL)
	return (0);
      chaine->size = 0;
      chaine->head = NULL;
      chaine->last = NULL;
    }

  return (chaine);
}

int	selectmain(char **av)
{
  t_list *chaine;

  chaine = list_chain(chaine);
  chaine = init_chain(chaine);
  return (0);
}
