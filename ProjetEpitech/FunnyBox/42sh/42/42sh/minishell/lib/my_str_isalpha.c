/*
** my_str_isalpha.c for my_str_isalpha in /home/boucha_q/rendu/Piscine-C-lib/my
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Wed Oct 23 14:41:05 2013 boucha_q
** Last update Wed Oct 23 14:44:44 2013 boucha_q
*/

int     my_str_isalpha(char *str)
{
  int	i;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	}
      else
      return (0);
      i = i + 1;
    }
  return (1);
}
