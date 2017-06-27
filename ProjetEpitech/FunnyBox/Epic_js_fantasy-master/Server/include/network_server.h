/*
** network_server.h for rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Server
** 
** Made by decouf_m
** Login   <decouf_m@epitech.net>
** 
** Started on  Sat May 10 13:05:22 2014 decouf_m
** Last update Sun May 11 04:27:10 2014 decouf_m
*/

#ifndef NETWORK_SERVER_H_
# define NETWORK_SERVER_H_

/*
** Include System
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
** Macro
*/

#define INVALID_SOCKE   -1
#define SOCKET_ERROR    -1
#define closesocket(param) close(param)
#define PORT		5151
#define BUFFER_SIZE	1024
#define MAX_CLIENTS	5

/*
** Les typedefs
*/
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

typedef struct s_server
{
  SOCKET sock;
  SOCKADDR_IN sin;
  int   on;
} t_server;

typedef struct s_client
{
  SOCKET	sock;
  char		*name[BUFFER_SIZE];
} t_client;

typedef	struct s_manage
{
  t_server	*s;
  t_client	c[MAX_CLIENTS];
  fd_set	rdfs;
  int		max_socket;
  int		nbr_client;
  socklen_t	len;
} t_manage;

#endif
                                                                                                                                      
