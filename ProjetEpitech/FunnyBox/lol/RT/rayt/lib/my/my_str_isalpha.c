/*
** my_str_isalpha.c for my_str_isalpha in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:14:08 2013 julien_t
** Last update Sat Oct 19 14:14:49 2013 julien_t
*/

int     my_str_isalpha(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        i++;
      else
        return (0);
    }
  return (1);
}
