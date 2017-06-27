/*
** network_client.h for rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Client
** 
** Made by decouf_m
** Login   <decouf_m@epitech.net>
** 
** Started on  Sat May 10 16:57:54 2014 decouf_m
** Last update Sat May 10 22:11:04 2014 decouf_m
*/

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
#define PORT            5151
#define BUFFER_SIZE     1024

/*
** Les typedefs
*/
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

typedef struct s_client
{
  SOCKET sock;
  SOCKADDR_IN sin;

} t_client;
