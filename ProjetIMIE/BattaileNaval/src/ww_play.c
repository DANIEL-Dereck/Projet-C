#include "my.h"
#include "ww.h"
#include <stdio.h>
#include <stdlib.h>

void init_map(int map[ZMAX][XMAX][YMAX])
{
  int z;
  int x;
  int y;

  for (z = 0; z <= ZMAX; z++)
    {
      for (x = 0; x <= XMAX; x++)
        {
          for (y = 0; y <= YMAX; y++)
            {
              map[z][x][y] = 0;
            }
        }
    }
}
/*
void nuke_map(int map[ZMAX][XMAX][YMAX], int z, int x, int y)
{
  int z;
  int x;
  int y;

  for (z = 0; z <= ZMAX; z++)
    {
      for (x = 0; x <= XMAX; x++)
        {
          for (y = 0; y <= YMAX; y++)
            {
	      if (map[z][x][y] == 0)
		map[z][x][y] = -2;
	      else
		map[z][x][y] = -1;
            }
        }
    }
}
*/
void aff_boat(int map[ZMAX][XMAX][YMAX], int z)
{
  int x = 0;
  int y = 0;
  int o = 0;
  char pos = 'A';
  char pis = 'A';

  my_printf("\n \t\033[032m<======= Carte Joueur %d =======>\033[039m\n  y ",z+1);
  for (o = 0; o < YMAX; o++){
    my_putchar(pos++);
    my_putchar(' ');}
  my_putchar('\n');
  my_printf("x +");
  for (o = 0; o <= (YMAX *2); o++)
    my_printf("-");
  my_printf("+\n");
  for (x = 0; x < XMAX; x++)
    {
      my_printf("%c | ", pis++);
      for (y = 0; y < YMAX; y++)
        {
          if (map[z][x][y] == -1)
	    my_printf("\033[031mX\033[039m ");
          else if (map[z][x][y] == -2)
	    my_printf("\033[031m0\033[039m ");
	  else if (map[z][x][y] != 0 && map[z][x][y] != -2 && map[z][x][y] != -1)
	    my_printf("\033[032m%d\033[039m ", map[z][x][y]);
          else
            my_printf("\033[036m%d\033[039m ", map[z][x][y]);
        }
      my_printf("| \n");
    }
  my_printf("  +");
  for (o = 0; o <= (YMAX *2); o++)
    my_printf("-");
  pos = 'A';
  my_printf("+\n");
}

void aff_boat_enm(int map[ZMAX][XMAX][YMAX], int z)
{
  int x = 0;
  int y = 0;
  int o = 0;
  char pos = 'A';
  char pis = 'A';

  my_printf("\n \t\033[032m<======= Carte Ennemie %d =======>\033[039m\n  y ",z+1);
  for (o = 0; o < YMAX; o++){
    my_putchar(pos++);
    my_putchar(' ');}
  my_putchar('\n');
  my_printf("x +");
  for (o = 0; o <= (YMAX *2); o++)
    my_printf("-");
  my_printf("+\n");
  for (x = 0; x < XMAX; x++)
    {
      my_printf("%c | ", pis++);
      for (y = 0; y < YMAX; y++)
        {
          if (map[z][x][y] == -1)
	    my_printf("\033[031mX\033[039m ");
          else if (map[z][x][y] == -2)
	    my_printf("\033[031m0\033[039m ");
	  else if (map[z][x][y] != 0 && map[z][x][y] != -2 && map[z][x][y] != -1)
	    my_printf("\033[036m0\033[039m ", map[z][x][y]);
          else
            my_printf("\033[036m%d\033[039m ", map[z][x][y]);
        }
      my_printf("| \n");
    }
  my_printf("  +");
  for (o = 0; o <= (YMAX *2); o++)
    my_printf("-");
  my_printf("+\n");
}

void ia_play(int player, int enm, int game[ZMAX][XMAX][YMAX], int *x, int *y, int nbp)
{
  do{
    if (AI == 0)
      {
	srand(time(NULL));
	*x = (rand() * time(NULL)) % XMAX;
	*x = correcrand(*x);
	*y = (rand() * time(NULL)) % YMAX;
	*y = correcrand(*y);
      }
    else if (AI == 1)
      {
	if (*x < XMAX)
	  *x += 1;
	else if (*y == YMAX)
	  {
	    *y = 0;
	    *x = 0;
	  }
	else
	  {
	    *y += 1;
	    *x = 0;
	  }
      }
  }while(game[enm][*x][*y] < 0);
  if (nbp == 3)
    aff_boat(game, player);
  my_printf("IA tire en %c / %c\n", *x+'A', *y+'A');
  if (game[enm][*x][*y] == 0 || game[enm][*x][*y] == -2)
    game[enm][*x][*y] = -2;
  else if (game[enm][*x][*y] > 0)
    game[enm][*x][*y] = -1;
}

void player_play(int player, int enm, int game[ZMAX][XMAX][YMAX])
{
  int a = 0;
  int x = 0;
  int y = 0;

  my_printf("\033[032mJoueur %d \033[039ma toi de jouer\n", player + 1);
  aff_boat(game, player);
  aff_boat_enm(game, enm);
  do{
    if (a > 0)
      my_printf("\033[031m ERROR : Vous avez deja jouer ici.\033[039m\n");
    y = ask_coord(y, 'y');
    if (y == -42)
      {
	aff_boat(game, enm);
	y = ask_coord(y, 'y');
      }
    x = ask_coord(x, 'x');
    a++;
  }while(game[enm][x][y] < 0);
  my_printf("Joueur %d tire en %c / %c\n",player + 1, x+'A', y+'A');
  if (game[enm][x][y] == 0 || game[enm][x][y] == -2)
    game[enm][x][y] = -2;
  else if (game[enm][x][y] > 0)
    game[enm][x][y] = -1;
}

int check_boat(int map[ZMAX][XMAX][YMAX], int z)
{
  int x = 0;
  int y = 0;
  for (x = 0; x < XMAX; x++)
    {
      for (y = 0; y < YMAX; y++)
        {
          if (map[z][x][y] > 0)
	    return (1);
        }
    }
  return (0);
}

void delir_ending(int play, int count)
{
  if(DELIRIUM == 1){
    if (play == 1)
      my_printf("AND THE WINNER IS ... \033[032mYOU !!!!\033[039m\n");
    else
      CapRandom();
    my_printf("\033[031mAND THE WINNER IS ... ME !!!!\n YOU ARE A BIG NOOB, THE CAPRANDOM KILL YOU\033[039m\n");
    while (count--)
      {
	usleep(TEMPS);
	printf("\r\033[031m THX FOR PLAYING \033[039m");
	usleep(TEMPS);
	printf("\r\033[032m THX FOR PLAYING \033[039m");
	usleep(TEMPS);
	printf("\r\033[033m THX FOR PLAYING \033[039m");
	usleep(TEMPS);
	printf("\r\033[034m THX FOR PLAYING \033[039m");
	usleep(TEMPS);
	printf("\r\033[035m THX FOR PLAYING \033[039m");
	usleep(TEMPS);
	printf("\r\033[036m THX FOR PLAYING \033[039m");
	usleep(TEMPS);
	printf("\r\033[037m THX FOR PLAYING \033[039m");
	usleep(TEMPS);
	printf("\r\033[038m THX FOR PLAYING \033[039m");
	usleep(TEMPS);
	printf("\r\033[039m THX FOR PLAYING \033[039m");
      }
  }
  else{
    if (play == 1)
      my_printf("\033[032mYou are the winner !!!\033[039m\n");
    else{
      CapRandom();
      my_printf("\033[031m You are the looser !!!!\033[039m\n");}
  }
}

void play_game(int game[ZMAX][XMAX][YMAX], int nbp)
{
  int iax1 = -1;
  int iax2 = -1;
  int iay1 = 0;
  int iay2 = 0;
  int count = 0;
  int play = 0;
  int enm = 1;

  do{
    if (play == 0)
      {
	if (nbp == 1){
	  my_printf("\n\t\033[031mJoueur %d, presse enter to play your turn\033[039m\n", play+1);
	  get_next_line(0);
	  player_play(play, enm, game);}
	else if (nbp == 2)
	  player_play(play, enm, game);
	else if (nbp == 3){
	  ia_play(play, enm, game, &iax1, &iay1, nbp);
	  usleep(TEMPSIA);}
	enm = 0;
	play = 1;
      }
    else if (play == 1)
      {
	if (nbp == 1){
	  my_printf("\n\t\033[031mJoueur %d, presse enter to play your turn\033[039m\n", play+1);
	  get_next_line(0);
	  player_play(play, enm, game);}
	else if (nbp == 2)
	  ia_play(play, enm, game, &iax2, &iay2, nbp);
	else if (nbp == 3)
	  ia_play(play, enm, game, &iax2, &iay2, nbp);
	enm = 1;
	play = 0;
      }
    count++;
  }while(check_boat(game, play));
  delir_ending(play, count);
}

int start_game(int game[ZMAX][XMAX][YMAX])
{
  int nbp;
  int uti;

  init_map(game);
  nbp = ask_nbplayer();

  if (nbp == 1){
    do{
      my_printf("\033[032mJoueur 1\033[039m voulez vous placer vos bateau (1) ou laisser le random choisir (2) ==> ");
      uti = my_getnbr(get_next_line(0));
    }while(uti != 1 && uti != 2);
    if (uti == 1)
      ask_boat(game, 0);
    else
      place_Rboat(game, 0);
    do{
      my_printf("\n\033[032mJoueur 2\033[039m voulez vous placer vos bateau (1) ou laisser le random choisir (2) ==> ");
      uti = my_getnbr(get_next_line(0));
    }while(uti != 1 && uti != 2);
    if (uti == 1)
      ask_boat(game, 1);
    else
      place_Rboat(game, 1);
  }
  else if (nbp == 2)
    {
      do{
	my_printf("Voulez vous placer vos bateau (1) ou en random (2) ==> ");
	uti = my_getnbr(get_next_line(0));
      }while(uti != 1 && uti != 2);
      if (uti == 1)
	ask_boat(game, 0);
      else
	place_Rboat(game, 0);
      place_Rboat(game, 1);
    }
  else if (nbp == 3)
    {
      place_Rboat(game, 0);
      place_Rboat(game, 1);
    }
  play_game(game, nbp);
  return 0;
}


void loadingue()
{
  int i = 0;

  if (DELIRIUM == 1){
    while (i < TEMPS_CHARGEMENT){
      my_printf("\rLoading .  ");
      usleep(TEMPS);
      my_printf("\rLoading .. ");
      usleep(TEMPS);
      my_printf("\rLoading ...");
      usleep(TEMPS);
      i++;
    }
  }
  my_putchar('\n');
}

void CapRandom()
{
  if (DELIRIUM == 1)
    my_printf("\t(\\_/)\n\t(\033[031m*\033[039mo\033[031m*\033[039m)\n\t(/.\\)\n\t()-()\n");
}

void presentation()
{
  /*  (\_/)  */
  /*  (*o*)  */
  /*  (/.\)  */
  /*  ()-()  */
  my_printf("+--------------------------------+\n");
  my_printf("|\t(\\_/)                    |\n|\t(\033[031m*\033[039mo\033[031m*\033[039m)                    |\n|\t(/.\\)                    |\n|\t()-()                    |\n");
  my_printf("+--------------------------------+\n");
  my_printf("|Bataille Naval v1.42            |\n");
  my_printf("|Crée par le Dereck DANIEL       |\n");
  my_printf("|Sponsoriser par le Capt'n Random|\n");
  my_printf("+--------------------------------+\n");
  CapRandom();
  loadingue();
}

int premierverif()
{
  int valmax;

  if (XMAX < YMAX)
    valmax = XMAX;
  else
    valmax = YMAX;

  if (XMAX < 10){
    my_printf("Taille du X maximum trop petite\n");
    return -1;}
  if (XMAX > 26){
    my_printf("Taille du X maximum trop grande\n");
    return -1;}
  if (YMAX < 10){
    my_printf("Taille du Y maximum trop petite\n");
    return -1;}
  if (YMAX > 26){
    my_printf("Taille du Y maximum trop grande\n");
    return -1;}
  if (NB_CORVETTE < 0){
    my_printf("Nombre de corvette invalide\n");
    return -1;}
  if (NB_DESTROYER < 0){
    my_printf("Nombre de destroyer invalide\n");
    return -1;}
  if (NB_CROISEUR < 0){
    my_printf("Nombre de croiseur invalide\n");
    return -1;}
  if (NB_PORTEAVION < 0){
    my_printf("Nombre de porte-avion invalide\n");
    return -1;}
  if (SIZE_CORVETTE <= 0 || SIZE_CORVETTE > valmax){
    my_printf("Taille de corvette invalide\n");
    return -1;}
  if (SIZE_DESTROYER <= 0 || SIZE_DESTROYER > valmax){
    my_printf("Taille de destroyer invalide\n");
    return -1;}
  if (SIZE_CROISEUR <= 0 || SIZE_CROISEUR > valmax){
    my_printf("Taille de croiseur invalide\n");
    return -1;}
  if (SIZE_PORTEAVION <= 0 || SIZE_PORTEAVION > valmax){
    my_printf("Taille de porte-avion invalide\n");
    return -1;}
  return 0;
}

int main()
{
  int ac;
  int game[ZMAX][XMAX][YMAX];

  if (premierverif() == -1)
    return -1;
  presentation();
  ac = start_game(game);
  return ac;
}
