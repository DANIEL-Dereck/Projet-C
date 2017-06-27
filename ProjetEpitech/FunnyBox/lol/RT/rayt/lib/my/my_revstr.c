/*
** *my_revstr.c for *my_revstr in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 13:50:37 2013 julien_t
** Last update Fri Oct 25 15:48:59 2013 julien_t
*/

char    *my_revstr(char *str)
{
  int   i;
  int   j;
  char  c;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i = i + 1;
      j = j - 1;
    }
  return (str);
}
