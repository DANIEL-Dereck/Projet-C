/*
** my_str_contains.c for colle in /home/gautie_a/rendu/colle2-daniel_d/src
** 
** Made by gautie_a
** Login   <gautie_a@epitech.net>
** 
** Started on  Tue May  6 14:32:03 2014 gautie_a
** Last update Tue May  6 14:32:35 2014 gautie_a
*/

int	my_str_contains(char *str, char c)
{
  while (str && *str)
    if (*str++ == c)
      return (1);
  return (0);
}
