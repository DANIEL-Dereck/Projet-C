/*
** my_strcmp.c for my_strcmp.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Oct 11 16:15:36 2013 daniel_d
** Last update Sun Oct 20 15:57:46 2013 daniel_d
*/

int	my_strlen(char *s)
{
  int a;

  a = 0;

  while (s[a] != '\0')
    a = a + 1;
  return (a);
}

int	my_strcmp(char *s1, char *s2)
{
  int b;
  int c;

  b = my_strlen(s1);
  c = my_strlen(s2);

  if (b > c)
      my_putchar('2');

  if (b < c)
    {
    my_putchar('-');
    my_putchar('2');
    }

  if (b == c)
    my_putchar('0');
}

