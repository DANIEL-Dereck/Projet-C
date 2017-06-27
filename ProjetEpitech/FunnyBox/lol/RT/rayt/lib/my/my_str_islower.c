/*
** my_str_islower.c for my_str_islower in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:18:02 2013 julien_t
** Last update Sat Oct 19 14:18:24 2013 julien_t
*/

int     my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
        {
          i = i + 1;
        }
      else
        {
          return (0);
        }
    }
  return (1);
}
