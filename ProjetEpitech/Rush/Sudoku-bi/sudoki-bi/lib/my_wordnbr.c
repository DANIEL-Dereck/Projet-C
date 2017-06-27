/*
** my_wordnbr.c for my_wordnbr in /home/bidard_v/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by bidard_v
** Login   <bidard_v@epitech.net>
** 
** Started on  Fri Oct 18 17:18:36 2013 bidard_v
** Last update Sat Mar  1 14:26:50 2014 bidard_v
*/

#include "my.h"

int     my_wordnbr(char *str)
{
  int   i;
  int   word;

  i = 0;
  word = 0;
  while (i < my_strlen(str) && str[i] != '\0')
    {
      if (str[i] >= '!' && str[i] <= '~')
        {
          word = word + 1;
          while (str[i] >= '!' && str[i] <= '~')
	    i = i + 1;
        }
      i = i + 1;
    }
  return (word);
}
