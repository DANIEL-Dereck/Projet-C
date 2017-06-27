/*
** my_strlen.c for my_strlen.c in /home/daniel_d/rendu/Piscine-C-Jour_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  9 09:56:02 2013 daniel_d
** Last update Wed Oct  9 09:58:24 2013 daniel_d
*/


int	my_strlen(char *str)
{
  int a;

  a = 0;

  while(str[a] != '\0')
    {
      a = a + 1;
    }
  return (a);
}
