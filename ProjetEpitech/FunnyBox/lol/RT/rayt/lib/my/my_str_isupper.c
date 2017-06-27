/*
** my_str_isupper.c for my_str_isupper in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:19:40 2013 julien_t
** Last update Sat Oct 19 14:20:07 2013 julien_t
*/

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
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
