/*
** my_strcpy.c for my_strcpy.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct  7 08:56:30 2013 daniel_d
** Last update Mon Oct 21 13:52:09 2013 daniel_d
*/

int	*my_strcpy(char *dest, char *src)
{
  my_putstr(src);
  dest = src;
  my_putstr(dest);
}
