/*
** *my_strlowcase.c for *my_strlowcase in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:08:13 2013 julien_t
** Last update Sat Oct 19 14:09:01 2013 julien_t
*/

char    *my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        {
          str[i] = str[i] + 32;
        }
      i = i + 1;
    }
  return (str);
}
