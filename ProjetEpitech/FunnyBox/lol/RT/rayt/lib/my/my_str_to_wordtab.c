/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/julien_t/rendu/PSU_2013_minishell1/lib/my
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Fri Jan  3 15:02:20 2014 julien_t
** Last update Tue Mar 11 16:36:17 2014 julien_t
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char    *my_strdup(char *str);

int     my_count_word(char *s)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  while (s[i])
    {
      if ((s[i] != ' ' && s[i] != '\t'))
        {
          cpt = cpt + 1;
          while (s[i] && ((s[i] != ' ' && s[i] != '\t')))
            i = i + 1;
        }
      i = i + 1;
    }
  return (cpt);
}

int     my_count_char(char *s, int *i)
{
  int   cpt;

  cpt = 0;
  while (s[*i] && ((s[*i] != ' ' && s[*i] != '\t')))
    {
      cpt = cpt + 1;
      *i = *i + 1;
    }
  return (cpt);
}

char    **my_str_to_wordtab(char *str)
{
  int   i;
  int   n;
  int   word;
  char  **tab;

  i = 0;
  n = 0;
  word = my_count_word(my_strdup(str));
  tab = (char **)malloc(sizeof(char *) * (word + 1));
  while (str[i] && word > 0)
    {
      if ((str[i] != ' ' && str[i] != '\t'))
        {
          tab[n] = my_strdup(str + i);
          tab[n][my_count_char(str, &i)] = '\0';
          n = n + 1;
          word = word - 1;
        }
      i = i + 1;
    }
  tab[my_count_word(my_strdup(str))] = NULL;
  tab[n] = NULL;
  return (tab);
}
