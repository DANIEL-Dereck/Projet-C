/*
** gestion_error.c for rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 14:04:57 2014 daniel_d
** Last update Sat May 10 14:05:10 2014 daniel_d
*/

int     resum_error(int *verif, int size)
{
  int   i;

  i = 0;
  while (i <= size)
    {
      if (verif[i] == -1)
        {
          return (-1);
        }
      i++;
    }
  return (0);
}
