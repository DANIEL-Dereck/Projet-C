/*
** sh.h for sh.h in /home/le-fra_g/minishel/include
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Fri May 16 16:46:12 2014 le-franc
** Last update Mon May 19 16:22:48 2014 le-franc
*/

#ifndef SH_H_
# define SH_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/* my_read.c */
char	*my_read();

/* my_42sh.c */
int	my_42sh(char **);

/*
** SOURCE_CHECK_ALIAS
*/

/* my_check_cmd_alias.c */
void	my_check_cmd_alias(char *, int, int);

/* my_check_name_alias.c */
void	my_check_name_alias(char *, int, int);

/* my_tmp_alias.c */
void	my_tmp_alias();

/* my_check_alias.c */
void	my_check_alias(char *, int, int);

/* my_check_equal.c */
void	my_check_equal(char *, int, int);

/* my_check_sh.c */
void	my_check_sh(int, int);

/* my_write_alias_int_tmp.c */
void	my_write_alias_in_tmp(char *, int);

/*
** SOURCES_EXEC_ALIAS
*/

/* my_alias.c */
char	*my_alias_in_buff(int, char **, char *);
char	*my_alias(char *);

/* my_cmd_buff_for_alias.c */
char	*my_cmd_buff_for_alias(char *, char *);

/* my_put_alias_in_buff.c */
char	*ret_before_egale(char *);
char	*my_check_same_alias2(char **, char *, char *, int);
char	*my_put_alias_in_buff(char *, char **, char *, char *);

/* my_realloc_tab.c */
char	**my_realloc_tab(char **, char *);

/*
** SOURCES_PATH
*/

/* fill_func_path.c */
int	my_strlen_space(char *);
char	*fill_func_path(char *, char *);

/* get_path.c */
int	my_match(char *, char *);
char	*fill_path(char **);
char	*get_path(char **);

/* my_path.c */
char	**my_path(char **, char *);

/*my_path_to_wordtab.c */
int	count_line_path(char *);
int	count_long_line_path(char *, int);
char	**fill_tab_path(char *, int, int, int);
char	**my_path_to_wordtab(char *);

#endif
