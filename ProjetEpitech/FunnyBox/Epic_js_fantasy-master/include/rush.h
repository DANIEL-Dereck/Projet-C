/*
** rush.h for rush in /home/cordon_b/rendu/rush2/Epic_js_fantasy/include
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Sat May 10 09:22:42 2014 cordon_b
** Last update Sat May 10 17:47:50 2014 cordon_b
*/

#ifndef RUSH_H_
#define RUSH_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "network_client.h"
#include "get_next_line.h"
#include "network_server.h"
#include "epic_editor.h"


/*------------PARSING FILE-------------*/

/*structure*/

typedef struct s_header
{
  char	*name;
  char	*start;
  char	*end;
  int	magic_number;
}t_header;

typedef struct s_champ
{
  char	*name;
  char	*type;
  int	health;
  int	speed;
  int	spe;
  int	deg;
  char	*weapon;
  char	*armor;
  struct s_champ	*next;
  struct s_champ	*prev;
}t_champ;

typedef struct s_monster
{
  char	*type;
  int	health;
  int	speed;
  int	spe;
  int	deg;
  char	*weapon;
  char	*armor;
  struct s_monster	*next;
  struct s_monster	*prev;
}t_monster;

typedef struct s_link
{
  char	*name;
  int	adv; //bool 1 ou 0 ?
  // lien salle
  char	**liaison; // plusieurs liaison ? tableau char ** ou liste imbriqué ?
  char	**tab;
  struct s_link	*next;
  struct s_link	*prev;
}t_link;

typedef struct s_global
{
  struct s_header	*header;
  struct s_champ	*champ;
  struct s_monster	*monster;
  struct s_link		*link;
}t_global;

/*proto*/

int	fill_the_list(t_global *global, char *str, int flag);
int	look_magic_number(t_global *global, char *str);
int	fill_header(t_global *global, char *str);
int	fill_champ(t_global *global, char *str);
int	fill_monster(t_global *global, char *str);
int	fill_header(t_global *global, char *str);
int	fill_link(t_global *global, char *str);
char    **str_to_wordtab(char *str, char sep);


/*-----------END------------*/


#endif
