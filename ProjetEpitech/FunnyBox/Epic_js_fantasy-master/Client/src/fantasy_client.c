/*
** fantasy_client.c for rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Client
** 
** Made by decouf_m
** Login   <decouf_m@epitech.net>
** 
** Started on  Sat May 10 14:56:50 2014 decouf_m
** Last update Sat May 10 17:22:05 2014 decouf_m
*/

#include "network_client.h"
#include "misc.h"

t_client	*connect_server()
{
  t_client	*client;

  if ((client = malloc(sizeof(*client))) == NULL)
    return (my_put_error_ptr("[Server] - Malloc() failled\n"));
  client->sock = socket(AF_INET, SOCK_STREAM, 0);
  client->sin.sin_addr.s_addr = inet_addr("127.0.0.1");
  client->sin.sin_family = AF_INET;
  client->sin.sin_port = htons(PORT);
  if(connect(client->sock, (SOCKADDR*)&client->sin, sizeof(client->sin)) != SOCKET_ERROR)
    printf("Connexion à %s sur le port %d\n", "127.0.0.1", PORT);
  else
    return (my_put_error_ptr("Impossible de se connecter\n"));
  return (client);
}

int main()
{
  t_client	*client;

  if ((client = connect_server()) == NULL)
    return (0);
  closesocket(client->sock);
  return EXIT_SUCCESS;
}
