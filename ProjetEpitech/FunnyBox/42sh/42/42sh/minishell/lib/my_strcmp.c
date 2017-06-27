/*
** my_strcmp.c for int my_strcmp(char *s1,char *s2) in /home/boucha_q/rendu/Piscine-C-Jour_06/ex_5
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
<<<<<<< HEAD
** Started on  Fri May 16 17:22:26 2014 le-franc
** Last update Tue May 20 14:24:06 2014 daniel_d
=======
** Started on  Sat Oct 19 16:31:45 2013 boucha_q
** Last update Thu Apr 24 14:36:02 2014 bouchard alexandre
>>>>>>> 6d762a1aa8372f3bfab197a933352077f8c249b5
*/

int	my_strcmp(char *str1, char *str2)
{
  int	a;
  int	n;
  n = 0;
  a = 0;
  while ( str1[a] != '\0' || str2[a] != '\0')
    {
<<<<<<< HEAD
      if (to_cmp[i] == with[i])
        n = 1;
      else
	return (0);
      i++;
=======
      if ( str1[a] != str2[a])
	{
	  n = str1[a] - str2[a];
	  return (n);
	}
      a = a + 1;
>>>>>>> 6d762a1aa8372f3bfab197a933352077f8c249b5
    }
  return (0);
}
