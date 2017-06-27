/*
** sub_func.c for sub_func in /home/besnie_b/Lem_in
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Sun May  4 22:08:09 2014 besnie_b
** Last update Sun May  4 23:24:05 2014 daniel_d
*/

#include "my.h"
#include "lem_in.h"

int     lem_in_func(char *str)
{
  char  **tab;

  tab = my_str_to_strtab(str);
  us_lem_in(tab);
  return (0);
}

void    clear_buffer(char *str)
{
  int   i;

  i = 2048;
  while (i >= 0)
    str[i--] = 0;
}

void    init_str(int *str, int nb)
{
  int   i;

  i = 0;
  while (i < (nb - 1))
    str[i++] = -1;
}

int     pos_room(char *str)
{
  int   i;

  i = 0;
  i = my_getnbr(str);
  return (i);
}

void    node_become_room(char *str, t_node *node)
{
  char  **tab;

  tab = my_str_to_wordtab(str);
  node->nom = tab[0];
  node->x = pos_room(tab[1]);
  node->y = pos_room(tab[2]);
  node->fourmi = 0;
}
