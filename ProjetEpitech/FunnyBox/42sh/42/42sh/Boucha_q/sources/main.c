/*
** main.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/my_read/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Thu Apr 24 14:09:45 2014 bouchard alexandre
** Last update Tue May 13 10:31:04 2014 daniel_d
*/

#include "../include/my_read.h"

char	*my_read()
{
  char	*buff;
  char	*tmp;
  int	rd;

  rd = 0;
  if ((buff = malloc(sizeof(char *) * 1)) == NULL)
    return (NULL);
  if ((tmp = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  buff[0] = '\0';
  tmp[1] = '\0';
  while ((rd = read(0, tmp, 1)) != 0 && rd != -1)
    {
      if (tmp[0] == '\n')
	return (buff);
      buff = my_strcat(buff, tmp);
    }
  return (NULL);
}

void    my_commande(char **path, char *cmd)
{
  if (!(my_strcmp(cmd[0], "env")))
    my_aff_env(elem);
  if (!(my_strcmp(cmd[0], "exit")))
    my_exit();
  else if (!(my_strcmp(cmd[0], "setenv")))
    my_setenv(elem, cmd);
  else if (!(my_strcmp(cmd[0], "cd")))
    my_cd(cmd);
  else
    my_execfunk(path, cmd);
}

int	main()
{
  char	*buff;
  char **cmd;
  int n;
  char *path;

  n = 0;
  my_putstr("&>");
  while ((buff = my_read()) != NULL)
    {
      my_putstr(buff);

      while (cmd[n])
        {
          if (cmd[n + 1] == NULL)
            cmd[n][my_strlen(cmd[n]) -1] = 0;
          n++;
        }

      if (buff[0] != '\0')
	my_putstr("\n");
      my_commande(path, cmd[0]);
      my_putstr("&>");
    }
  my_putstr("exit\n");
  return (0);
}
