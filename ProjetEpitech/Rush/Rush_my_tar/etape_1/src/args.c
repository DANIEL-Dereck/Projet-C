/*
** args.c for my_tar in /home/bertho_d/rendu/rush_my_tar
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Fri Nov 29 20:55:40 2013 bertho_d
** Last update Sat Nov 30 18:13:55 2013 bertho_d
*/

#include <stdlib.h>
#include "my.h"
#include "my_tar.h"

int	add_flag(int flag, int flags)
{
  if (flags & flag)
    return (flags);
  return (flags + flag);
}

int	set_archive_name(char *arg, char *next_arg, int *i, t_args *args)
{
  char *name;

  if (!arg || !i || !args)
    return (ALLOC_ERROR);
  if ((arg[1]))
    name = arg + 1;
  else
    {
      name = next_arg;
      *i += 1;
    }
  if (!name || *name == '\0')
    return (NO_ARCH_NAME);
  if (args->archive_name)
    return (MUL_ARCH_NAME);
  args->archive_name = my_strdup(name);
  return (0);
}

int	get_options(char *arg, t_args *args, char *next_arg, int *i)
{
  int	pos;

  if (!arg || !args)
    return (ALLOC_ERROR);
  while (*arg)
    {
      if (*arg == 'v')
	args->flags = add_flag(VERBOSE_FLAG, args->flags);
      else if (*arg == 'p')
	args->flags = add_flag(PERMS_FLAG, args->flags);
      else if ((pos = my_find_char(*arg, MODE_OPTIONS)) != -1)
	{
	  if (args->mode == -1)
	    args->mode = pos;
	  else
	    return (MUL_MODE);
	}
      else if (*arg == 'f')
	return (set_archive_name(arg, next_arg, i, args));
      else
	return (*arg + INV_OPTION);
      arg += 1;
    }
  return (0);
}

void	init_args(t_args *args)
{
  if (!args)
    return ;
  args->mode = -1;
  args->flags = 0;
  args->archive_name = NULL;
  args->files = NULL;
}

int	get_args(int argc, char **argv, t_args *args)
{
  int	i;
  int	error;
  char	*next_arg;

  if (!argv || !args)
    return (ALLOC_ERROR);
  init_args(args);
  i = 0;
  while (i < argc)
    {
      if (argv[i][0] == '-' && argv[i][1])
	{
	  next_arg = ((i < argc - 1) ? argv[i + 1] : NULL);
	  if ((error = get_options(argv[i] + 1, args, next_arg, &i)))
	    return (error);
	}
      else if (!(args->files = list_new_elem(my_strdup(argv[i]),
					     args->files))
	       || !(args->files->data))
	return (ALLOC_ERROR);
      i += 1;
    }
  if (args->mode == -1)
    return (NO_MODE);
  return (0);
}
