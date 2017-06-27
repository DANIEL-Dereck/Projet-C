/*
** my_tar.c for my_tar in /home/bertho_d/rendu/rush_my_tar
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Fri Nov 29 20:36:45 2013 bertho_d
** Last update Sun Dec  1 02:22:36 2013 bertho_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"
#include "my_tar.h"

int	disp_error(char *argv0, int error)
{
  char *mess[NB_ERRORS];

  if (!argv0)
    return (error);
  mess[0] = "%s: unknown error\n";
  mess[ALLOC_ERROR] = "%s: allocation error\n";
  mess[NO_ARCH_NAME] = "%s: option requires an argument -- 'f'\n";
  mess[MUL_ARCH_NAME] = "%s: you may not specify more than one archive file\n";
  mess[NO_MODE] = "%s: you must specify one of the \"-xct\" options\n";
  mess[MUL_MODE] = "%s: you may not specify more than one \"-xct\" option\n";
  mess[CMODE_NOARGS] = "%s: Cowardly refusing to create an empty archive\n";
  mess[INVALID_HEADER] = "%s: This does not look like a tar archive\n";
  if (error >= INV_OPTION - (1 << 7) && error < INV_OPTION + (1 << 7))
    {
      my_printf("%s: invalid option -- '%c'\n", argv0, (error - INV_OPTION));
      return (error);
    }
  if (error < 0 || error >= NB_ERRORS)
    error = 0;
  if (errno)
    perror(argv0);
  else
    my_printf(mess[error], argv0);
  return ((error) ? error : UNKNOWN_ERROR);
}

int		main(int argc, char **argv)
{
  t_args	args;
  int		error;

  if ((error = get_args(argc -1, &argv[1], &args)))
    return (disp_error(argv[0], error));
  if (args.mode == CREATE_MODE)
    {
      if ((error = new_archive(&args)))
	return (disp_error(argv[0], error));
    }
  else if (args.mode == EXTRACT_MODE || args.mode == LIST_MODE)
    {
      if ((error = open_archive(&args)))
	return (disp_error(argv[0], error));
    }
  return (0);
}
