/*
** my_putstr.c for my_putstr in /home/daniel_d/rendu/Piscine-C-Jour_11/do-op
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct 28 14:34:07 2013 daniel_d
** Last update Mon Oct 28 14:35:33 2013 daniel_d
*/

void	my_putstr(char *str)
{
  int a;

  a = 0;

  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}
