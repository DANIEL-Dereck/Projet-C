/*
** mysh.h for my_sh.h in /home/le-fra_g/42sh/Greg/include
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Mon May 12 15:53:26 2014 le-franc
** Last update Tue May 13 16:50:54 2014 daniel_d
*/

#ifndef MYSH_H_
# define MYSH_H_

#include <sys/types.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "my.h"

#define PROMPT "$>"

void    usage(char *sh);
int     shmain(char **env);

int     my_prompt(char **env);
char    *my_read();
char    **my_check_cmd(char *cmd, char **env);

/*
** BUILTIN
*/

int     my_cd(char *buffer, char **env);
int     my_cd_exec(char *buffer);
int     my_gohome(char **env);
int     my_cd_tiret(char **env);
int     take_direction(char *home);
char    *cpydirec(int l, char *str, char *buffer);
int     aff_directory(char *env, int pos);

int     my_echo(char *buffer);
int     check_start(char *buffer);
int     parsing_echo(char *buffer);
int     my_check(char c);
int     check_optn(int optn, int opt);
int     my_optn_e_maj(char *buffer);
int     my_optn_e_min(char *buffer);

int     my_exit(char *buffer);

void    get_sigall();
int     signal_set();

/*
** EXEC CMD
*/

int     count_line_path(char *path);
int     count_long_line_path(char *str, int j);
char	**fill_tab_path(char *path, int c, int i, int j);
char    **my_path_to_wordtab(char *path);

int     my_tablen(char **tab);
char    **my_path(char **path, char **env);
char    *my_access(char **path, char *cmd);
int     exec_cmd(char **tabcmd, char **env);
int     my_exec_cmd(char *cmd, char **path, char **env);
int     my_exec(char *cmd, char **env);

/*
** TEMPORAIRE
*/

char    **my_setenv(char *cmd, char **env);
char    **my_unsetenv(char *cmd, char **env);

#endif
