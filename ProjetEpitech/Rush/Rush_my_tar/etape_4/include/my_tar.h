/*
** my_tar.h for my_tar in /home/bertho_d/rendu/rush_my_tar
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Fri Nov 29 20:47:10 2013 bertho_d
** Last update Sun Dec  1 21:37:03 2013 bertho_d
*/

#ifndef MY_TAR_H_
# define MY_TAR_H_

#include <sys/stat.h>

# define READ_SIZE	512

# define UNKNOWN_ERROR	-3
# define OPEN_ERROR	-1
# define ALLOC_ERROR	1
# define NO_ARCH_NAME	2
# define MUL_ARCH_NAME	3
# define NO_MODE	4
# define MUL_MODE	5
# define CMODE_NOARGS	6
# define INVALID_HEADER	7
# define NB_ERRORS	8
# define INV_OPTION	(1 << 8)

# define VERBOSE_FLAG	(1 << 0)
# define PERMS_FLAG	(1 << 2)

# define EXTRACT_MODE	0
# define CREATE_MODE	1
# define LIST_MODE	2

# define MODE_OPTIONS	"xct"

typedef struct s_args
{
  int mode;
  int flags;
  char *archive_name;
  t_list *files;
} t_args;

typedef struct s_header
{
  char name[100];
  char mode[8];
  char uid[8];
  char gid[8];
  char size[12];
  char mtime[12];
  char checksum[8];
  char typeflag;
  char linkname[100];
  char magic[6];
  char version[2];
  char uname[32];
  char gname[32];
  char devmajor[8];
  char devminor[8];
  char prefix[155];
  char pad[12];
} t_header;

/*
**utils.c
*/
void	copy_n_bytes(char *dest, char *src, int n);
int	write_n_chars(int fd, char c, int len);
char	*get_file_content(int fd, int *len);
int	get_permissions(t_header *header);
char	*add_slash(char *str);

/*
**args.c
*/
int	add_flag(int flag, int flags);
int	set_archive_name(char *arg, char *next_arg, int *i, t_args *args);
int	get_options(char *arg, t_args *args, char *next_arg, int *i);
void	init_args(t_args *args);
int	get_args(int argc, char **argv, t_args *args);

/*
**header.c
*/
char		get_typeflag(struct stat *file_stat);
unsigned int	calc_checksum(t_header *header);
void		fill_header(t_header *header, char *file_name,
			    struct stat *file_stat);
int		is_header_correct(t_header *header);
int		is_header_empty(t_header *header);

/*
**create_archive.c
*/
int	archive_file(int archive_fd, char *file_name,
		     struct stat *file_stat, int new_fd);
int	archive_dir_loop(int archive_fd, char *dir_path,
			 char *file_name, int verbose);
int	archive_dir_content(int archive_fd, char *dir_path,
			    struct stat *dir_stat, int verbose);
int	archive_filedir(int archive_fd, char *file_name, int verbose);
int	new_archive(t_args *args);

/*
**open_archive.c
*/
int	ignore_file(char *file_name, t_args *args);
int	extract_file(int archive_fd, t_header *header, unsigned int file_len);
int	extract_filedirlink(int archive_fd, t_header *header, t_args *args);
int	list_file_name(int fd, t_header *header, t_args *args);
int	open_archive(t_args *args);

/*
**disp_infos.c
*/
void	disp_date(int time);
void	disp_mode(int mode);

#endif
