/*
** my_putstr.c for my_putstr in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Thu Oct 10 09:34:22 2013 julien_t
** Last update Mon Oct 21 15:19:14 2013 julien_t
*/

int	 my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
    return (0);
}
