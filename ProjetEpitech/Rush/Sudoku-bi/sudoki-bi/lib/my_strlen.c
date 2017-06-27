/*
** my_strlen.c for my_strlen.c in /home/daniel_d/rendu/Piscine-C-Jour_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  9 09:56:02 2013 daniel_d
** Last update Sat Mar  1 15:18:06 2014 bidard_v
*/

int	my_strlen(char *str)
{
  int a;

  a = 0;
  while (str[a])
    a++;
  return (a);
}
