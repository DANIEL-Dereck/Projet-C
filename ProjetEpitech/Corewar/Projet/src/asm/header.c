/*
** header.c for asm in /home/daniel_d/rendu/CPE_2014_Corewar/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Apr  7 14:20:50 2014 daniel_d
** Last update Sun Apr 13 22:54:21 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "asm.h"
#include "op.h"

int	write_name(char *str, int fdnf)
{
  int	i;
  char	c;

  i = 1;
  c = 0;
  my_putchar('\t');
  if (str == NULL)
    return (ERROR3);
  while (str[i] != '\"')
    {
      write(0, &str[i], 1);
      write(fdnf, &str[i++], 1);
    }
  while (i <= PROG_NAME_LENGTH)
    {
      write(fdnf, &c, 1);
      i++;
    }
  my_putchar('\n');
  return (0);
}

void	write_comment(char *str, int fdnf)
{
  int	i;
  char	c;

  i = 1;
  c = 0;
  my_putchar('\t');
  if (str != NULL)
    while (str[i] != '\"')
      {
	write(0, &str[i], 1);
	write(fdnf, &str[i++], 1);
      }
  while (i <= COMMENT_LENGTH)
    {
      write(fdnf, &c, 1);
      i++;
    }
  my_putchar('\n');
}

int	my_header(int fdnf, char *buffer, int ligne)
{
  int	magic;
  char	**commande;

  magic = COREWAR_EXEC_MAGIC;
  commande = sepa(buffer);
  if (commande[0] == NULL)
    return (ERROR2);
  if (my_strcmp(commande[0], NAME_CMD_STRING) == 2 && ligne == 1)
    {
      write(fdnf, &magic, 1);
      if (commande[1][0] == '\0')
	{
	  my_printf("ERROR : No name for your Champion\n");
	  return (ERROR3);
	}
      write_name(commande[1], fdnf);
    }
  else if (ligne == 2)
    write_comment(commande[1], fdnf);
  else
    return (0);
  return (0);
}
