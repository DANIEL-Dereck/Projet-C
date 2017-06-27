/*
** epic_editor.h for rush in /home/daniel_d/rendu/rush-epic_js_fantasy/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 09:12:01 2014 daniel_d
** Last update Sat May 10 17:34:14 2014 daniel_d
*/

#ifndef EPIC_EDITOR_H_
# define EPIC_EDITOR_H_

/*
** Attributes
*/
#define NAME "1" // string in parameters (0x01)
#define ROOM_TO_WIN "2" // string in parameters (0x02)
#define ROOM_TO_START "3" // string in parameters (0x03)
#define TYPE "4" // string in parameters (0x04)
#define HP "5" // value in parameters (0x05)
#define SPEED "6" // value in parameters (0x06)
#define DEG "7" // value in parameters (0x07)
#define WEAPON "8" // string in parameters (0x08)
#define ARMOR "9" // string in parameters (0x09)
#define ADV "10" // string in parameters (0x10)
#define TAB_CONNECTION "11" // string in parameters (0x11)
#define TAB_MONSTER "12" // string in parameters (0x12)
#define ROOM "13" // string in parameters (0x0F)
#define SPE "14" // value in parameters (0x20)
/*
** Section
*/
#define CHAMPION "15" // no parameters (0x0C)
#define HEADER "16" // no parameters (0x0D)
#define MONSTER "17" // no parameters (0x0E)
/*
** Others
*/
#define SPE_SECTION "18" // no parameters (0x0A)
#define MAGIC_NUMBER "123" // no parameters (0x123)
/*
** utile
*/
#define LF "\n"
#define SPACE " "
#define PASS "PASS\n"
#define CMAX 12
#define MMAX 10
#define RMAX 20

typedef struct s_headerg
{
  char	*name;
  char	*room_to_win;
  char	*room_to_start;
} t_headerg;

typedef struct s_championg
{
  char	*name;
  char	*type;
  char	*hp;
  char	*spe;
  char	*speed;
  char	*deg;
  char	*weapon;
  char	*armor;
} t_championg;

typedef struct s_monsterg
{
  char	*type;
  char	*hp;
  char	*spe;
  char	*speed;
  char	*deg;
  char	*weapon;
  char	*armor;
} t_monsterg;

typedef struct s_roomg
{
  char	*name;
  char	*adv;
  char	*tab_connection;
  char	*tab_monster;
} t_roomg;

/*
** creat_file
*/
int     remp_file(int fd, char **tab);
int     creat_file(char *name, char **tab);
/*
** remp_file
*/
t_headerg        *init_header(t_headerg *h);
t_championg      *init_champion(t_championg *c);
t_monsterg       *init_monster(t_monsterg *m);
t_roomg  *init_room(t_roomg *r);
int     add_file(int fd, char *option, char *str, int bool);
int	header(int fd, t_headerg *h);
int     remp_header(int fd);
int	champion(int fd, t_championg *c);
int     remp_champion(int fd);
int	monster(int fd, t_monsterg *m);
int     remp_monster(int fd);
int	room(int fd, t_roomg *r);
int     remp_room(int fd);
int     resum_error(int *verif, int size);

#endif
