/*
** *my_strstr.c for *my_strstr in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 13:54:14 2013 julien_t
** Last update Mon Oct 21 15:17:48 2013 julien_t
*/

char    *my_strstr(char *str, char *to_find)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  while (str[i])
    {
      if (str[i] == to_find[cpt])
        {
          cpt = cpt + 1;
        }
      else
        {
          cpt = 0;
        }
      if (!to_find[cpt])
        {
          i = i - (cpt - 1);
          return (str + i);
        }
      i = i + 1;
    }
}
