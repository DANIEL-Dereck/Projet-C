/*
** my_revstr.c for char *my_revstr(char *str) in /home/boucha_q/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Oct  7 14:59:33 2013 boucha_q
** Last update Tue Oct  8 21:54:05 2013 boucha_q
*/

char	my_revstr(char *str)
{
  char i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  while (str[i] >= 0)
    {
      my_putchar(str[i]);
      i = i - 1;
    }
  return (str[i]);
}
