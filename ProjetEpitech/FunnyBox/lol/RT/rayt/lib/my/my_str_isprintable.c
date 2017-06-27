/*
** my_str_isprintable.c for my_str_isprintable in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:26:03 2013 julien_t
** Last update Sat Oct 19 14:26:37 2013 julien_t
*/

int     my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 32 && str[i] <= 126)
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
