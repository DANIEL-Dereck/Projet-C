/*
** open_archive.c for my_tar in /home/bertho_d/rendu/rush_my_tar
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sun Dec  1 00:35:54 2013 bertho_d
** Last update Sun Dec  1 21:44:07 2013 bertho_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_defines.h"
#include "my_tar.h"

int		ignore_file(char *file_name, t_args *args)
{
  t_list	*list;

  if (!file_name || !args)
    return (1);
  if (!(args->files))
    return (0);
  list = args->files;
  while (list)
    {
      if (my_strncmp(file_name, list->data,
		     MIN(my_strlen(file_name),
			 my_strlen(list->data))) == 0)
	return (0);
      list = list->next;
    }
  return (1);
}

int	extract_file(int archive_fd, t_header *header, unsigned int file_len)
{
  char	*content;
  int	new_fd;

  if (!header)
    return (ALLOC_ERROR);
  if ((new_fd = open(header->name, O_WRONLY | O_CREAT | O_TRUNC,
		     get_permissions(header))) == -1)
    return (OPEN_ERROR);
  if (!(content = malloc(file_len * sizeof(char))))
    return (ALLOC_ERROR);
  if (read(archive_fd, content, file_len) != file_len)
    return (UNKNOWN_ERROR);
  write(new_fd, content, file_len);
  close(new_fd);
  return (0);
}

int		extract_filedirlink(int archive_fd, t_header *header, t_args *args)
{
  unsigned int	file_len;

  if (!args)
    return (ALLOC_ERROR);
  file_len = my_getnbr_base(header->size, "01234567");
  if (file_len % 512 != 0 && header->typeflag != '5'
      && header->typeflag != '2')
    lseek(archive_fd, (512 - (file_len % 512)), SEEK_CUR);
  if (ignore_file(header->name, args))
    {
      if (header->typeflag != '5' && header->typeflag != '2')
	lseek(archive_fd, file_len, SEEK_CUR);
      return (0);
    }
  if (args->flags & VERBOSE_FLAG)
    my_printf("%s\n", header->name);
  if (header->typeflag == '5')
    return (mkdir(header->name, get_permissions(header)));
  if (header->typeflag == '2')
    return (symlink(header->linkname, header->name));
  return (extract_file(archive_fd, header, file_len));
}

int		list_file_name(int fd, t_header *header, t_args *args)
{
  unsigned int	file_len;

  if (!header || !args)
    return (ALLOC_ERROR);
  file_len = my_getnbr_base(header->size, "01234567");
  if (file_len % 512 != 0)
    file_len += 512 - (file_len % 512);
  if (header->typeflag != '5' && header->typeflag != '2')
    lseek(fd, file_len, SEEK_CUR);
  if (ignore_file(header->name, args))
    return (0);
  if (args->flags & VERBOSE_FLAG)
    {
      my_putchar((header->typeflag == '5') ? 'd'
		 : ((header->typeflag == '2') ? 'l' : '-'));
      disp_mode(my_getnbr_base(header->mode, "01234567"));
      my_printf("%s/%s %d ", header->uid, header->gid,
		my_getnbr_base(header->size, "01234567"));
      disp_date(my_getnbr_base(header->mtime, "01234567"));
    }
  my_printf("%s\n", header->name);
  return (0);
}

int		open_archive(t_args *args)
{
  int		fd;
  int		error;
  t_header	header;

  if (!args)
    return (ALLOC_ERROR);
  if ((fd = open(args->archive_name, O_RDONLY)) == -1)
    return (OPEN_ERROR);
  while (read(fd, &header, sizeof(header)) == sizeof(header))
    {
      if (!is_header_empty(&header))
	{
	  if (!is_header_correct(&header))
	    return (INVALID_HEADER);
	  if (my_strstr(header.name, "/PaxHeaders."))
	    lseek(fd, 512, SEEK_CUR);
	  else if (args->mode == EXTRACT_MODE &&
		   (error = extract_filedirlink(fd, &header, args)))
	    return (error);
	  else if (args->mode == LIST_MODE &&
		   (error = list_file_name(fd, &header, args)))
	    return (error);
	}
    }
  return (0);
}
