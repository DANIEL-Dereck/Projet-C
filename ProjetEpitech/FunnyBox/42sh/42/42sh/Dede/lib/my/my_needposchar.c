/*
** my_needposchar.c for my_needposchar in /home/daniel_d/rendu/Prog_test/Lib/lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec  5 12:44:37 2013 daniel_d
** Last update Fri Dec  6 10:06:22 2013 daniel_d
*/

int     my_needposchar(char *str, char c)
{
  int   r;

  r = 0;
  while (str[r] != '\0')
    {
      if (str[r] == c)
        return (r);
      r = r + 1;
    }
  return (-1);
}
