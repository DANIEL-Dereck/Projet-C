/*
** my_ls.c for my_ls in /home/daniel_d/rendu/PSU_2013_my_ls
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Nov 25 09:18:17 2013 daniel_d
** Last update Sun Dec  8 11:35:09 2013 daniel_d
*/

#include <dirent.h>
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <time.h>
#include "Lib/include/my.h"

char	**my_tab(char **mois)
{
  mois[0] = "Jan";
  mois[1] = "Fev";
  mois[2] = "Mar";
  mois[3] = "Avr";
  mois[4] = "May";
  mois[5] = "Jun";
  mois[6] = "Jul";
  mois[7] = "Aug";
  mois[8] = "Sep";
  mois[9] = "Oct";
  mois[10] = "Nov";
  mois[11] = "Dec";
  return (mois);
}

int     my_ls(DIR *dirp)
{
  struct dirent *entry;
  struct stat buf;

  while ((entry = readdir(dirp)) != NULL)
    {
      stat(entry->d_name, &buf);
      my_printf("%s ",entry->d_name);
    }
  my_putchar('\n');
  closedir(dirp);
  return (0);
}

int     my_ls_l(DIR *dirp, char **mois)
{
  struct dirent *entry;
  struct stat buf;
  struct passwd *result;
  struct group *grp;
  struct tm *time;

  while ((entry = readdir(dirp)) != NULL)
    {
      stat(entry->d_name, &buf);
      result = getpwuid(buf.st_uid);
      grp = getgrgid(buf.st_gid);
      time = gmtime(&buf.st_mtime);
      my_dir(buf);
      my_user_perm(buf);
      my_groupe_perm(buf);
      my_other_perm(buf);
      my_printf("\t%d\t%s\t%s\t%d\t%s\t%d\t%d:%d\t%s\n", buf.st_nlink,
		result->pw_name,grp->gr_name, buf.st_size, mois[time->tm_mon],
		time->tm_mday, time->tm_hour+1, time->tm_min, entry->d_name);
    }
  closedir(dirp);
  return (0);
}

int	my_testerror(char **av, int a)
{
  DIR	*dirp;
  char	**mois;

  dirp = opendir(av[a]);
  if (dirp == NULL)
    {
      my_printf("stderr. '[ERROR] : opendir probléme'\n");
      return (0);
    }
  mois = malloc(sizeof(mois) * 12);
  if (mois == NULL)
    return (0);
  mois = my_tab(mois);
  if (a == 1)
    my_ls(dirp);
  else if (a == 2)
    my_ls_l(dirp, mois);
  free(mois);
  return (0);
}

int	main(int ac, char **av)
{
  int   a;

  a = 1;
  if (ac < 2)
    av[a] = "./";
  if (av[1][0] == '-' && av[1][1] == 'l')
    a = a + 1;
  if (av[a] == NULL)
    av[a] = "./";
  my_testerror(av, a);
  return (0);
}
