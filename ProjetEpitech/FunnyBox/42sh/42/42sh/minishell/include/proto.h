/*
** proto.h for  in /home/boucha_q/rendu/PSU_42
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 14 09:03:31 2014 bouchard alexandre
** Last update Tue May 20 14:10:34 2014 bouchard alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include <string.h>
/*string pour realloc tab a enlever refaire strdup*/
#ifndef PROTO_H_
# define PROTO_H_

char    *my_get_nextline(int fd);

/*exec des alias*/
char    *my_alias(char *buff);
char    *my_cmd_buff_for_alias(char *buff, char *line);
char    **my_realloc_tab(char **tab, char *str);
char    *ret_before_egale(char *str);
char    *my_check_same_alias(char **tab, char *buff, char *ind, int i);
char    *my_check_same_alias2(char **tab, char *buff, char *ind, int i);
char    *my_put_alias_in_buff(char *buff, char **tab, char *ind, char *indtmp);

/*check des alias*/
void	my_tmp_alias();
void    my_check_sh(int fd_sh, int  fd_tmp);
void    my_check_alias(char *str, int countline_sh, int fd_tmp);
void    my_check_equal(char *str, int countline_sh, int fd_tmp);
void    my_check_name_alias(char *str, int countline_sh, int fd_tmp);
void    my_check_cmd_alias(char *str, int countline_sh, int fd_tmp);
void    my_write_alias_in_tmp(char *str, int fd_tmp);
char    *my_get_nextline(int fd);

/*my_read*/
char	*my_read();

/*my_42sh*/
int     my_42sh(char **env);

/*FUNC PATH*/

/*fillfunctpath*/
int     my_strlen_space(char *str);
char    *fill_func_path(char *path, char *buff);

/*get_path*/
char    *get_path(char **env);
char    *fill_path(char **env);
int     my_match(char *str, char *str1);

/*my_path*/
char    **my_path(char **env, char *buff);

/*my_path_to_wordtab*/
char    **my_path_to_wordtab(char *path);
char    **fill_tab_path(char *path, int c, int i, int j);
int     count_long_line_path(char *str, int j);
int     count_line_path(char *path);



#endif
