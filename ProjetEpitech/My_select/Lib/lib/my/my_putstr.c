/*
** my_putstr.c for my_putstr.c in /home/daniel_d/rendu/Piscine-C-Jour_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Oct  3 18:07:56 2013 daniel_d
** Last update Tue Nov 19 11:32:26 2013 daniel_d
*/

int	my_putstr(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}
