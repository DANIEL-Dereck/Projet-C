/*
** count_x_char.c for lib in /home/daniel_d/rendu/MUL_2013_fdf/Lib/lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Dec  8 21:16:08 2013 daniel_d
** Last update Sun Dec  8 21:16:50 2013 daniel_d
*/

int	count_x_char(char *str, char c)
{
  int   count;
  int	i;

  count = 0;
  while (str != '\0')
    {
      if (str[i] == c)
	count++;
      i++;
    }
  return (count);
}
