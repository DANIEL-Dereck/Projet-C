/*
** link_all.c for epic_rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 22:03:50 2014 daniel_d
** Last update Sat May 10 22:05:23 2014 daniel_d
*/

int     add_in_file(int fd, char *option, char *str, int bool)
{
  if (write(fd, option, strlen(option)) == -1)
    return (-1);
  if (str != NULL)
    {
      if (write(fd, SPACE, 1) == -1)
        return (-1);
      if (write(fd, str, strlen(str)) == -1)
        return (-1);
    }
  if (bool == 0)
    {
      if (write(fd, SPACE, 1) == -1)
        return (-1);
    }
  else if (bool == 1)
    {
      if (write(fd, LF, 1) == -1)
        return (-1);
    }
  return (0);
}

int     resum_error(int *verif, int size)
{
  int   i;

  i = 0;
  while (i <= size)
    {
      if (verif[i] == -1)
        {
          return (-1);
        }
      i++;
    }
  return (0);
}

int     remp_file(int fd, char **tab)
{
  remp_header(fd);
  if (write(fd, PASS, 5) == -1)
    return (-1);
  remp_champion(fd);
  if (write(fd, PASS, 5) == -1)
    return (-1);
  remp_monster(fd);
  if (write(fd, PASS, 5) == -1)
    return (-1);
  remp_room(fd);
  printf("Name of the game : %s\n", tab[1]);
  return (0);
}

int     question_prime(char *str, int min, int max)
{
  char  buffer[1024];
  int   result;
  int   r;

  printf("enter number of %s in %d and %d pleaz ?\n", str, min, max);
  while ((r = read(0, buffer, 1025)) != -1)
    {
      result = atoi(buffer);
      if (result > max || result < min)
        printf("ERROR : invalid number\n");
      else
        return (result);
      printf("enter number of %s in %d and %d ?\n", str, min, max);
    }
  return (-1);
}

