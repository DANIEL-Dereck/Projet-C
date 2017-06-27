/*
** create_archive.c for my_tar in /home/bertho_d/rendu/rush_my_tar
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Nov 30 22:17:13 2013 bertho_d
** Last update Sun Dec  1 20:55:28 2013 bertho_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include "my.h"
#include "my_tar.h"

int		archive_file(int archive_fd, char *file_name,
			     struct stat *file_stat, int new_fd)
{
  t_header	header;
  char		*content;
  int		len;

  if (!file_name || !file_stat)
    return (ALLOC_ERROR);
  fill_header(&header, file_name, file_stat);
  if (!(content = get_file_content(new_fd, &len)) && len == 0)
    return (ALLOC_ERROR);
  if (len == -1)
    len = 0;
  if (S_ISLNK(file_stat->st_mode))
    sprintf(header.linkname, "%.99s", content);
  sprintf(header.checksum, "%.6o", calc_checksum(&header));
  write(archive_fd, &header, sizeof(header));
  if (!S_ISLNK(file_stat->st_mode))
    {
      if (len)
	write(archive_fd, content, len);
      if (len % 512 != 0)
	write_n_chars(archive_fd, 0, 512 - len % 512);
    }
  free(content);
  return (0);
}

int		archive_dir_loop(int archive_fd, char *dir_path,
				 char *file_name, int verbose)
{
  char	*file_path;
  int	error;

  if (my_strcmp(file_name, ".") == 0 || my_strcmp(file_name, "..") == 0)
    return (0);
  file_path = my_strcat_alloc(dir_path, file_name);
  if ((error = archive_filedir(archive_fd, file_path, verbose)))
    return (error);
  return (0);
}

int		archive_dir_content(int archive_fd, char *dir_path,
				    struct stat *dir_stat, int verbose)
{
  DIR		*dir;
  struct dirent	*dirp;
  t_header	header;
  int		error;

  if (!dir_path || !dir_stat)
    return (ALLOC_ERROR);
  fill_header(&header, dir_path, dir_stat);
  sprintf(header.checksum, "%.6o", calc_checksum(&header));
  write(archive_fd, &header, sizeof(header));
  if (!(dir = opendir(dir_path)))
    return (OPEN_ERROR);
  dir_path = add_slash(dir_path);
  while ((dirp = readdir(dir)))
    if ((error = archive_dir_loop(archive_fd, dir_path,
				  dirp->d_name, verbose)))
      return (error);
  free(dir_path);
  closedir(dir);
  return (0);
}

int		archive_filedir(int archive_fd, char *file_name, int verbose)
{
  struct stat	file_stat;
  int		error;
  int		fd;

  if (!file_name)
    return (ALLOC_ERROR);
  if (verbose)
    my_printf("%s\n", file_name);
  if (stat(file_name, &file_stat) == -1)
    return (UNKNOWN_ERROR);
  if (S_ISDIR(file_stat.st_mode))
    archive_dir_content(archive_fd, file_name, &file_stat, verbose);
  else
    {
      if ((fd = open(file_name, O_RDONLY)) == -1)
	return (UNKNOWN_ERROR);
      if ((error = archive_file(archive_fd, file_name, &file_stat, fd)))
	return (error);
      close(fd);
    }
  return (0);
}

int		new_archive(t_args *args)
{
  int		fd;
  int		error;
  t_list	*elem;

  if (!(args->files))
    return (CMODE_NOARGS);
  fd = 1;
  if (args->archive_name)
    if ((fd = open(args->archive_name, O_WRONLY | O_CREAT | O_TRUNC,
		   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
      return (OPEN_ERROR);
  elem = args->files;
  while (elem)
    {
      if ((error = archive_filedir(fd, elem->data,
				   (args->flags & VERBOSE_FLAG))))
	return (error);
      elem = elem->next;
    }
  if (fd != 1)
    close(fd);
  return (0);
}
