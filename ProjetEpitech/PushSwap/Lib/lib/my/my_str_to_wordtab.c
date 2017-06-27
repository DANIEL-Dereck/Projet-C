/*
** my_str_to_wordtab.c for strtowordtab in /home/daniel_d/rendu
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Jan  4 15:02:32 2014 daniel_d
** Last update Mon Jan  6 21:19:49 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>

int	my_count_word(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

int	my_count_char(char *str)
{
  int   i;

  i = 0;
  while ((str[i] != ' ') && (str[i] != '\0') && (str[i] != '\n'))
    i++;
  i = i + 1;
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  char  **wordtab;
  int   i;
  int   b;
  int   a;

  b = 0;
  i = 0;
  a = 0;
  if ((wordtab = malloc(sizeof(wordtab) * ((my_count_word(str) + 1)))) == NULL)
    return (0);
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        {
          while (str[i] == ' ')
            i++;
          a++;
          b = 0;
        }
      if ((wordtab[a] = malloc(sizeof(*wordtab) * ((my_count_char(str + i) + 1)
						   ))) == NULL)
	return (0);
      while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
        wordtab[a][b++] = str[i++];
      wordtab[a][b] = '\0';
    }
  wordtab[a + 1] = 0;
  return (wordtab);
}
