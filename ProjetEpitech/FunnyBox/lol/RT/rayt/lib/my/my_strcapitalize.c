/*
** *my_strcapitalize.c for *my_strcapitalize in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:10:08 2013 julien_t
** Last update Sat Oct 19 14:12:52 2013 julien_t
*/

char    *my_strcapitalize(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] = str[i] + 32;
      if (str[i] >= 'a' && str[i] <= 'z'
          && ((str[i - 1] >= 32 && str[i - 1] <= 47) ||
              str[i - 1] >= 58 && str[i - 1] <= 63 ||
              str[i - 1] >= 91 && str[i - 1] <= 9 ||
              str[i] == str[0]))
        {
          str[i] = str[i] - 32;
        }
      i = i + 1;
    }
  return (str);
}
