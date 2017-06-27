/*
** rtv1.h for  in /home/le-coa_m/rendu/MUL_2013_rtv1
**
** Made by Maxime LE COAT
** Login   <le-coa_m@epitech.net>
**
** Started on  Wed Mar 12 15:40:00 2014 Maxime LE COAT
** Last update Sun Jun  8 19:22:03 2014 Maxime LE COAT
*/

#include "mlx.h"
#include "colorHEX.h"
#include "ray.h"

#ifndef RTV1_H_
# define RTV1_H_

/*
** Informations
*/

# define VERSION        "Rt - V1.0b8"

/*
** Internal Settings
*/

# define DEBUG_MODE     1

/*
** Configuration
*/

# define COLOR_MSG	WHITE
# define CLEAN		"\e[0;0H\e[2J"

/*
** Textures working directory
*/

# define WOOD_XPM	"./textures/wood.xpm"

/*
** my_display_engine
*/

void    display_loading(char *);
void    display_msg(t_window *, char *);
void    display_time(int, int, int);

#endif /* !RTV1_H__ */
