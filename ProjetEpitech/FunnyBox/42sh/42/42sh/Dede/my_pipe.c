/*
** my_pipe.c for Pipes in /home/aubry_f/rendu/42sh/pipes
** 
** Made by aubry_f
** Login   <aubry_f@epitech.net>
** 
** Started on  Thu May 22 16:47:09 2014 aubry_f
** Last update Sat May 24 11:30:35 2014 aubry_f
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

int	son_pipe(int fd[2], char **command, char **env)
{
  close(fd[1]);
  if ((dup2(fd[0], 0)) == -1)
    {
      printf("ERROR : dup2 failed\n");
      return (-1);
    }
  close(fd[0]);
  if ((execve(command[0], command, env)) == -1)
    {
      printf("ERROR : exec %s failed\n", command[0]);
      return (-1);
    }
  return (0);
}

int	father_pipe(int fd[2], char **command, char **env)
{
  close(fd[0]);
  if ((dup2(fd[1], 1)) == -1)
    {
      printf("ERROR : dup2 failed\n");
      return (-1);
    }
  close(fd[1]);
  if ((execve(command[0], command, env)) == -1)
    {
      printf("ERROR : exec %s failed\n", command[0]);
      return (-1);
    }
  return (0);
}

int	my_pipes(char **command1, char **command2, char **env)
{
  int	fd[2];
  int	pid;

  if (pipe(fd) == -1)
    {
      printf("ERROR : pipe didn't work\n");
      return (-1);
    }
  if ((pid = fork()) < 0)
    {
      printf("ERROR : fork didn't work\n");
      return (-1);
    }
  if (pid == 0)
    son_pipe(fd, command2, env);
  else
    father_pipe(fd, command1, env);
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  char	*command1[3]; // double tableau contenant la commande + ses options
  command1[0] = "/bin/ls";
  command1[1] = "-l";
  command1[2] = NULL;

  char	*command2[2]; // deuxième double tableau pour la deuxième commande
  command2[0] = "/bin/more";
  command2[1] = NULL;

  my_pipes(ls, wc, env);
}
