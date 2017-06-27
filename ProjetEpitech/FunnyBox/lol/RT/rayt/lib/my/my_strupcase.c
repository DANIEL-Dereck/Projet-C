/*
** *my_strupcase.c for *my_strupcase in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:02:19 2013 julien_t
** Last update Sat Oct 19 14:02:58 2013 julien_t
*/

char    *my_strupcase(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
        {
          str[i] = str[i] - 32;
        }
      i = i + 1;
    }
  return (str);
}
