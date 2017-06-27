/*
** my_strlen.c for strlen in /home/aubry_f/rendu/42sh/setenv
** 
** Made by aubry_f
** Login   <aubry_f@epitech.net>
** 
** Started on  Wed Apr 23 16:37:38 2014 aubry_f
** Last update Wed Apr 23 16:38:03 2014 aubry_f
*/

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != 0)
    a++;
  return (a);
}
