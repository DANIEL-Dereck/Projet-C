/*
** mysh.h for my_sh.h in /home/le-fra_g/42sh/Greg/include
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Mon May 12 15:53:26 2014 le-franc
** Last update Tue May 13 13:57:36 2014 daniel_d
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
** TEMPORAIRE
*/

void    my_exec(char *cmd, char **env);
char    **my_setenv(char *cmd, char **env);
char    **my_unsetenv(char *cmd, char **env);

#endif
