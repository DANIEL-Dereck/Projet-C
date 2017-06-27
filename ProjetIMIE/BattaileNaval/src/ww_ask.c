#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "ww.h"

int ask_nbplayer()
{
  int nbp = 0;

  do{
  my_printf("Vous voulez jouer :\n");
  my_printf(" - Contre un autre joueur (1)\n");
  my_printf(" - Contre une inteligence artificiel (2)\n");
  my_printf(" - Voir 2 inteligence artificiel se combatre (3)\n");
  my_printf("========> ");
  nbp = my_getnbr(get_next_line(0));
  }while(nbp != 1 && nbp != 2 && nbp != 3);
  return nbp;
}


/* Demande une coordonée à l'utilisateur.
** renvoie une coordonée entré par l'utilisateur
*/
int ask_coord(int coord, char c)
{
  char *tmp;
  int coordmax;

  if (c == 'x')
    coordmax = XMAX;
  else
    coordmax = YMAX;

  do{
    my_printf("Entrer coord %c into A and %c: ==> ", c, coordmax+'A' - 1);
  tmp = get_next_line(0);

  if (my_strcmp(tmp,"CHEAT") == 0)
    return (-42);

  if (tmp[0] >= 'A' && tmp[0] <= 'Z')
	coord = tmp[0] - 'A' + 1;
  else
    coord = my_getnbr(tmp);
  coord--;

  }while (coord < 0 || coord >= coordmax);
  return coord;
}

/*
** Demande une entré utilisateur du sens verticale ou horizontale
*/
char ask_sens(char c)
{
  char *tmp;

  my_printf("Entrer le sens Verticale (v)/ Horizontale (h)/ : ==> ");
  tmp = get_next_line(0);
  c = tmp[0];
  my_printf("\n");
  return c;
}

/*
** Demande une entré utilisateur de l'ID du bateau
*/
int ask_boat_id()
{
  int boat = 0;

  do {
    my_printf("Entrer 1) to place Corvette\nEntrer 2) to place Destroyer\nEntrer 3) to place Croiseur\nEnt\
rer 4) to place Porte-avion\n ==> ");
    boat = my_getnbr(get_next_line(0));
    my_printf("\n");
    if (boat != ID_CORVETTE && boat != ID_DESTROYER && boat != ID_CROISEUR && boat != ID_PORTEAVION)
      my_printf("\033[031m<=o=> Try Again <=o=>\033[039m\n");
  }while (boat != ID_CORVETTE && boat != ID_DESTROYER && boat != ID_CROISEUR && boat != ID_PORTEAVION);
  return boat;
}

/*
** Fonction principale pour le placement des bateaux
*/
void ask_boat(int game[ZMAX][XMAX][YMAX], int ia)
{
  int nb_corv = NB_CORVETTE;
  int nb_dest = NB_DESTROYER;
  int nb_croi = NB_CROISEUR;
  int nb_port = NB_PORTEAVION;
  int nb_bot = nb_corv + nb_dest + nb_croi + nb_port;
  int nb = 1;
  int id = 0;
  int x = 0;
  int y = 0;
  char sens;
  int verif = 0;
  int flag = 1;

  my_printf("Chargement des paramétre :\n");
  loadingue();
  my_printf("\t<=====> Placer vos bateau <=====>\n");
  do{
    aff_boat(game, 0);
    my_printf(" <== Bateau à placer %d/%d ==>\n", nb, nb_bot);
    if (nb_corv != 0)
      my_printf("\033[032m\t%d * corvette restant     ***\n\033[039m", nb_corv);
    else
      my_printf("\033[031m\t%d * corvette restant     ***\n\033[039m", nb_corv);

    if (nb_dest != 0)
      my_printf("\033[032m\t%d * destroyer restant    ***\n\033[039m", nb_dest);
    else
      my_printf("\033[031m\t%d * destroyer restant    ***\n\033[039m", nb_dest);
    if (nb_croi != 0)
      my_printf("\033[032m\t%d * croiseur restant     ***\n\033[039m", nb_croi);
    else
      my_printf("\033[031m\t%d * croiseur restant     ***\n\033[039m", nb_croi);

    if (nb_port != 0)
      my_printf("\033[032m\t%d * porte-avion restant  ***\n\033[039m",nb_port);
    else
      my_printf("\033[031m\t%d * porte-avion restant  ***\n\033[039m",nb_port);

    id = ask_boat_id();
    if (id == ID_CORVETTE && nb_corv == 0)
      my_printf("\t\033[031m<===> Nombre de corvette insufisant <===>\033[039m\n\t<===> Merci de changer de bateau <===>\n\
");
    else if (id == ID_DESTROYER && nb_dest == 0)
      my_printf("\t\033[031m<===> Nombre de destroyer insufisant <===>\033[039m\n\t<===> Merci de changer de bateau <===>\\
n");
    else if (id == ID_CROISEUR && nb_croi == 0)
      my_printf("\t\033[031m<===> Nombre de croiseur insufisant <===>\033[039m\n\t<===> Merci de changer de bateau <===>\n\
");
    else if (id == ID_PORTEAVION && nb_port == 0)
      my_printf("\t\033[031m<===> Nombre de porte-avion insufisant <===>\033[039m\n\t<===> Merci de changer de bateau <===\
>\n");
    else{
      do{
	y = ask_coord(y, 'y');
	x = ask_coord(x, 'x');
	sens = ask_sens(sens);

	if (id == ID_CORVETTE)
	  verif = VerifBoat(game, ia, x, y, sens, SIZE_CORVETTE);
	else if (id == ID_DESTROYER)
	  verif = VerifBoat(game, ia, x, y, sens, SIZE_DESTROYER);
	else if (id == ID_CROISEUR)
	  verif = VerifBoat(game, ia, x, y, sens, SIZE_CROISEUR);
	else if (id == ID_PORTEAVION)
	  verif = VerifBoat(game, ia, x, y, sens, SIZE_PORTEAVION);

	if (verif == 0)
	  {
	    if (((x > XMAX || x < 0) || (y > YMAX || y < 0)) && (sens != SENSV && sens != SENSH))
	      printf("\033[031m <== ERREUR saisie coord, Try again ==> \033[39m\n");
	    else
	      {
		if (id == ID_CORVETTE)
		  nb_corv--;
		else if (id == ID_DESTROYER)
		  nb_dest--;
		else if (id == ID_CROISEUR)
		  nb_croi--;
		else if (id == ID_PORTEAVION)
		  nb_port--;
		place_boat(game, id, ia, x, y, sens);
		nb++;
		flag = 0;
	      }
	  }
	else{
	  printf("\033[031m <== ERREUR Bateau deja present a la position demander ==>\n");
	  printf("\t<== Try again ==>\033[039m\n");}
      }while(flag);
    }
    flag = 1;
  }while(nb <= nb_bot);
}

