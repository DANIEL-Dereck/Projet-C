/*
** my_str_isnum.c for my_str_isnum in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:15:47 2013 julien_t
** Last update Sat Oct 19 14:16:12 2013 julien_t
*/

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
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
