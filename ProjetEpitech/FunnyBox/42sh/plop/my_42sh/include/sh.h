/*
** proto.h for sh.h in /home/le-fra_g/lol/my_42sh
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Tue May 20 16:34:05 2014 le-franc
** Last update Sun May 25 23:36:41 2014 daniel_d
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
#include <sys/types.h>
#include <sys/wait.h>

typedef struct          s_list
{
  char          *envir;
  struct s_list *next;
}t_list;

/* my_read.c */
char    *my_read();

/* my_42sh.c */
int     my_42sh(t_list *);

/* my_signal.c */
void    get_sigall();
int     signal_set();

/*
** SOURCE_CHECK_ALIAS
*/

/* my_check_cmd_alias.c */
void    my_check_cmd_alias(char *, int, int);

/* my_check_name_alias.c */
void    my_check_name_alias(char *, int, int);

/* my_tmp_alias.c */
void    my_tmp_alias();

/* my_check_alias.c */
void    my_check_alias(char *, int, int);

/* my_check_equal.c */
void    my_check_equal(char *, int, int);

/* my_check_sh.c */
void    my_check_sh(int, int);

/* my_write_alias_int_tmp.c */
void    my_write_alias_in_tmp(char *, int);

/*
** SOURCES_EXEC_ALIAS
*/

/* my_alias.c */
char    *my_alias_in_buff(int, char **, char *);
char    *my_alias(char *, int);

/* my_cmd_buff_for_alias.c */
char    *my_cmd_buff_for_alias(char *, char *);

/* my_put_alias_in_buff.c */
char    *ret_before_egale(char *);
char    *my_check_same_alias2(char **, char *, char *, int);
char    *my_put_alias_in_buff(char *, char **, char *, char *);

/* my_realloc_tab.c */
char    **my_realloc_tab(char **, char *);

/*
** SOURCES_PATH
*/

/* fill_func_path.c */
int     my_strlen_space(char *);
char    *fill_func_path(char *, char *);

/* get_path.c */
int     my_match(char *, char *);
char    *fill_path(t_list *);
char    *get_path(t_list *);

/* my_path.c */
char    **my_path(t_list*, char *);

/*my_path_to_wordtab.c */
int     count_line_path(char *);
int     count_long_line_path(char *, int);
char    **fill_tab_path(char *, int, int, int);
char    **my_path_to_wordtab(char *);

/*
** SOURCES_BULTINS
*/

/* my_env.c*/
void    my_env(t_list **);

/* my_env_in_list.c*/
t_list  *my_env_in_list(t_list *, char **);

/* my_setenv.c*/
int	match_test(t_list **, char *);
void	list_overwrite(t_list **, char *, int);
char	*new_envir(char *, char **, int);
int	name_check(char *);
t_list	*my_setenv(char **, t_list *, int);

/* put_tail_list.c*/
int     put_tail_list(t_list **, char *);

/* my_unsetenv.c*/
int	match_testbis(t_list **, char *);
int	list_cancel(t_list **, int);
t_list	*my_unsetenv(char **, t_list *);

/* my_cdbis.c*/
int     aff_directory(char *, int);
char    *cpydirec(int l, char *, char *);

/* my_cd.c*/
int     take_direction(char *, char *);
int     my_cd_tiret(t_list *);
int     my_gohome(t_list *);
int     my_cd_exec(char *);
t_list  *my_cd(char *, t_list *);

/* my_echo.c*/
int     my_echo(char *);
int     check_start(char *);

/* my_echobis.c*/
int     my_optn_e_min(char *);
int     my_optn_e_maj(char *);

/* my_exit.c*/
int     my_exit(char *);

/*check_builtins.c */
t_list  *send_cd(char **, t_list *, int);
t_list  *send_setenv(char **, t_list *, int);
int	send_exit(char **, int);
void	send_echo(char **, int);
t_list	*check_builtins(char **, t_list *, int *);

/*my_exec_cmd.c*/
int	count_list(t_list *);
char	**init_env(t_list *);
int	my_exec_cmd(char **, char **, t_list *);
int     exec_bis(char **path, char **tab_cmd);

/*
** SOURCE_REDIRECTION
*/

/* redirection_right.c */
t_list	*my_redir_right(char *, char *, t_list *);
t_list	*my_double_redir_right(char *, char *, t_list *);

/* my_parse.c */
t_list	*my_exec_total(t_list *, char *, int *);
t_list	*my_parse(char *, t_list *);

/* separator.c */
t_list	*my_semicolon(char *, char *, t_list *);
t_list	*my_or(char *, char *, t_list *);
t_list	*my_and(char *, char *, t_list *);

/* pars_redir.c */
int	my_count_with_sep(int, char *);
int	my_count_sep(char *);
char	**my_remp_tab(char **, char *, int, int);
char	**init_more_tab(char *, char **, int *);
char	**pars_redirection(char *);

#endif
