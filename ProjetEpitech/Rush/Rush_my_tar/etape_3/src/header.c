/*
** header.c for my_tar in /home/bertho_d/rendu/rush_my_tar
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Nov 30 21:29:29 2013 bertho_d
** Last update Sun Dec  1 01:34:10 2013 bertho_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"
#include "my_tar.h"

char	get_typeflag(struct stat *file_stat)
{
  if (!file_stat)
    return (0);
  if (S_ISREG(file_stat->st_mode))
    return ('0');
  if (S_ISLNK(file_stat->st_mode))
    return ('2');
  if (S_ISCHR(file_stat->st_mode))
    return ('3');
  if (S_ISBLK(file_stat->st_mode))
    return ('4');
  if (S_ISDIR(file_stat->st_mode))
    return ('5');
  if (S_ISFIFO(file_stat->st_mode))
    return ('6');
  return (0);
}

unsigned int	calc_checksum(t_header *header)
{
  unsigned int	sum;
  char		*bytes;
  unsigned int	i;

  if (!header)
    return (0);
  sum = 0;
  i = 0;
  bytes = (void *)header;
  while (i < sizeof(*header))
    {
      sum += bytes[i];
      i += 1;
    }
  return (sum);
}

void		fill_header(t_header *header, char *file_name,
			    struct stat *file_stat)
{
  struct passwd	*u_infos;
  struct group	*g_infos;

  if (!header || !file_name || !file_stat
      || !(u_infos = getpwuid(file_stat->st_uid))
      || !(g_infos = getgrgid(file_stat->st_gid)))
    return ;
  my_memset((void *)header, 0, sizeof(*header));
  sprintf(header->name, "%.99s", file_name);
  sprintf(header->mode, "%.7o", file_stat->st_mode % 512);
  sprintf(header->uid, "%.7o", file_stat->st_uid);
  sprintf(header->gid, "%.7o", file_stat->st_gid);
  sprintf(header->size, "%.11lo", file_stat->st_size);
  sprintf(header->mtime, "%.11lo", time(NULL));
  sprintf(header->checksum, "%.8s", "        ");
  header->typeflag = get_typeflag(file_stat);
  sprintf(header->magic, "ustar");
  sprintf(header->version, "00");
  sprintf(header->uname, "%.31s", u_infos->pw_name);
  sprintf(header->gname, "%.31s", g_infos->gr_name);
  sprintf(header->devmajor, "0000000");
  sprintf(header->devminor, "0000000");
}

int		is_header_correct(t_header *header)
{
  unsigned int	checksum;

  if (!header)
    return (0);
  checksum = my_getnbr_base(header->checksum, "01234567");
  copy_n_bytes(header->checksum, "        ", 8);
  if (checksum != calc_checksum(header))
    return (0);
  return (1);
}

int		is_header_empty(t_header *header)
{
  unsigned int	i;
  char		*bytes;

  if (!header)
    return (1);
  bytes = (char *)header;
  i = 0;
  while (i < sizeof(*header))
    if (bytes[i++])
      return (0);
  return (1);
}
