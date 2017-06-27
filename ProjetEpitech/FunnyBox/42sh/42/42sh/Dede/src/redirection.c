/*
** redirection.c for redir in /home/daniel_d/rendu/42/42sh/Dede/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue May 20 14:26:08 2014 daniel_d
** Last update Wed May 21 11:24:42 2014 daniel_d
*/

char	*redirection(char *cmd)
{
  int	pid;
  int	fd[2];
  char	*str;

  if (pipe(fd) != 0)
    return (NULL);
  if ((pid = fork() == -1)
      return (NULL);
  if (pid == 0)
    dup2(fd, 1);
  else
    wait(pid);
  return (str);
}
