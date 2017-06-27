/*
** my_exeparc.c for minishell in /home/daniel_d/rendu/PSU_2013_minishell2/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Mar  7 13:58:06 2014 daniel_d
** Last update Sun Mar  9 23:10:59 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_minishell.h"
#include "my.h"

int	my_count_part(char *buffer)
{
  int	i;
  int	a;

  a = 0;
  i = 0;
  while (buffer[i] != '\0' && buffer[i] != '\n')
    {
      if (buffer[i] == '|' || buffer[i] == ';' ||
          buffer[i] == '<' || buffer[i] == '>')
        a++;
      i++;
    }
  return (a);
}

char	**my_str_buffer_alloc(char *buffer, char **tabcmd)
{
  int	a;
  int	i;
  int	l;

  a = 0;
  i = 0;
  l = 0;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    {
      while (buffer[i] != '|' && buffer[i] != ';' &&
	     buffer[i] != '<' && buffer[i] != '>' &&
	     buffer[i] != '\n' && buffer[i] != '\0')
	{
	  i++;
	  a++;
	}
      if ((tabcmd[l] = malloc(sizeof(*tabcmd) * (a))) == NULL)
	return (NULL);
      a = 0;
      l++;
      i++;
    }
  return (tabcmd);
}

char	**my_str_to_buffer(char *buffer, char **tabcmd)
{
  int	a;
  int	i;
  int	l;

  i = 0;
  l = 0;
  a = 0;
  tabcmd = my_str_buffer_alloc(buffer, tabcmd);
  while (buffer[i] != '\n' && buffer[i] != '\0')
    {
      while (buffer[i] != '|' && buffer[i] != ';' &&
	     buffer[i] != '<' && buffer[i] != '>' &&
	     buffer[i] != '\n' && buffer[i] != '\0')
	{
	  tabcmd[l][a] = buffer[i];
	  a++;
	  i++;
	}
      l++;
      a = 0;
      i++;
    }
  return (tabcmd);
}

int     my_parscmd(char **envp, char *buffer)
{
  char	**tabcmd;
  int	i;

  i = 0;
  if ((buffer = my_epur_str(buffer)) == NULL)
      return (-1);
 if ((tabcmd = malloc(sizeof(tabcmd) * (my_count_part(buffer) + 1))) == NULL)
    return (-1);
  tabcmd = my_str_to_buffer(buffer, tabcmd);
  while (tabcmd[i] != NULL)
    {
      if ((tabcmd[i] = my_epur_str(tabcmd[i])) == NULL)
	return (-1);
      run_cmd(envp, tabcmd[i]);
      i++;
    }
  i = 0;
  while (tabcmd[i] != NULL)
    free(tabcmd[i++]);
  free(tabcmd);
  return (0);
}
