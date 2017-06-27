/*
** my_droit.c for my_ls in /home/daniel_d/rendu/PSU_2013_my_ls
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Dec  1 10:55:22 2013 daniel_d
** Last update Sun Dec  1 13:58:02 2013 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "Lib/include/my.h"

int	my_dir(struct stat buf)
{
  if (buf.st_mode & S_IFDIR)
    my_putchar('d');
  else
    my_putchar('-');
  return (0);
}

int	my_user_perm(struct stat buf)
{
  if (buf.st_mode & S_IRUSR)
    my_putchar('r');
  else
    my_putchar('-');
  if (buf.st_mode & S_IWUSR)
    my_putchar('w');
  else
    my_putchar('-');
  if (buf.st_mode & S_IXUSR)
    my_putchar('x');
  else
    my_putchar('-');
  return (0);
}

int	my_groupe_perm(struct stat buf)
{
  if (buf.st_mode & S_IRGRP)
    my_putchar('r');
  else
    my_putchar('-');
  if (buf.st_mode & S_IWGRP)
    my_putchar('w');
  else
    my_putchar('-');
  if (buf.st_mode & S_IXGRP)
    my_putchar('x');
  else
    my_putchar('-');
  return (0);
}

int	my_other_perm(struct stat buf)
{
  if (buf.st_mode & S_IROTH)
    my_putchar('r');
  else
    my_putchar('-');
  if (buf.st_mode & S_IWOTH)
    my_putchar('w');
  else
    my_putchar('-');
  if (buf.st_mode & S_IXOTH)
    my_putchar('x');
  else
    my_putchar('-');
  return (0);
}
