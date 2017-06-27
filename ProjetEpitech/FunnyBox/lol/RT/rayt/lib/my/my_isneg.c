/*
** my_isneg.c for my_isneg in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Fri Oct 18 21:11:34 2013 julien_t
** Last update Fri Oct 25 15:46:56 2013 julien_t
*/

int	 my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar('N');
    }
  else
    {
      my_putchar('P');
    }
  return (0);
}
