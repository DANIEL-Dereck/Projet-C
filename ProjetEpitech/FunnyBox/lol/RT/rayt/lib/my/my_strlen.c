/*
** my_strlen.c for my_strlen in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Fri Oct 18 21:23:51 2013 julien_t
** Last update Fri Oct 18 21:26:55 2013 julien_t
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  return (i);
}
