/*
** my_echobis.c for echo in /home/daniel_d/rendu/42/42sh/Dede/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue May 13 11:09:51 2014 daniel_d
** Last update Tue May 13 11:53:00 2014 daniel_d
*/

#include "mysh.h"

int     my_optn_e_maj(char *buffer)
{
  int   cote;
  int   i;

  cote = 0;
  i = check_start(buffer);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == 34 && buffer[i - 1] != 92 && cote == 0)
        cote = 1;
      else if (buffer[i] == 34 && buffer[i - 1] != 92 && cote == 1)
        cote = 0;
      else
        {
          if (cote == 0)
            {
              if (buffer[i] == 92)
                i++;
              write(1, &buffer[i], 1);
            }
          else
            write(1, &buffer[i], 1);
        }
      i++;
    }
  return (0);
}

int     my_optn_e_min(char *buffer)
{
  int   cote;
  int   i;

  cote = 0;
  i = check_start(buffer);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == 34 && buffer[i - 1] != 92 && cote == 0)
        cote = 1;
      else if (buffer[i] == 34 && buffer[i - 1] != 92 && cote == 1)
        cote = 0;
      else
        {
          if (cote == 0)
            {
              if (buffer[i] == 92)
                i++;
              write(1, &buffer[i], 1);
            }
          else
            write(1, &buffer[i], 1);
        }
      i++;
    }
  return (0);
}
