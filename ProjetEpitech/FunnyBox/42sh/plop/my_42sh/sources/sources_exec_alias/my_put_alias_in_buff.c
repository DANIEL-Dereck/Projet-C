/*
** my_put_alias_in_buff.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/exec_alias/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Thu May 15 16:19:42 2014 bouchard alexandre
** Last update Tue May 20 16:43:13 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

char    *ret_before_egale(char *str)
{
  char  *tmp;
  int   i;

  i = -1;
  tmp = malloc(sizeof(*tmp) * 1000);
  while (str[++i] != '\0' && str[i] != '=')
    tmp[i] = str[i];
  tmp[i] = '\0';
  return (tmp);
}

char    *my_check_same_alias2(char **tab, char *buff, char *ind, int i)
{
  if ((my_strcmp((ret_before_egale(tab[i + 1])), buff)) == 0)
    ind[i] = '1';
  return (ind);
}

char    *my_check_same_alias(char **tab, char *buff, char *ind, int i)
{
  while (i >= 0)
    ind = my_check_same_alias2(tab, buff, ind, i--);
  return (ind);
}

char    *my_put_alias_in_buff(char *buff, char **tab, char *ind, char *indtmp)
{
  int   i;
  int   j;
  char  *bufftmp;

  i = -1;
  while (tab[++i] != NULL);
  j = i;
  while ((my_strcmp(ind, indtmp)) == -1)
    {
      indtmp = ind;
      while (--i >= 0)
        {
          if ((my_strcmp(tab[i], "alias")) == 0 && ind[i] != '1')
            if ((bufftmp = my_cmd_buff_for_alias(buff, tab[i + 1])) != NULL)
              {
                ind = my_check_same_alias(tab, buff, ind, i);
                buff = bufftmp;
		bufftmp = NULL;
                i = j;
              }
        }
      i = j;
    }
  return (buff);
}
