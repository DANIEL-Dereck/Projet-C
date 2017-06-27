#include "ww.h"
#include "my.h"

int correcrand(int nb)
{
  if (nb < 0)
    nb = nb * -1;
  return nb;
}

void place_all(int game[ZMAX][XMAX][YMAX], int z, int x, int y, char sens, int size, int id)
{
  int i = 0;

  x = correcrand(x);
  y = correcrand(y);
  if (sens != SENSV && sens != SENSH)
    sens = SENSV;
  if (sens == SENSV)
    {
      if (x + size < XMAX){
	for (i = 0; i < size; i++)
	  game[z][x++][y] = id;
      }
      else if (x - size >= 0){
	for (i = 0; i < size; i++)
	  game[z][x--][y] = id;
      }
    }
  else if (sens == SENSH)
    {
      if (y + size < YMAX){
	for (i = 0; i < size; i++)
	  game[z][x][y++] = id;
      }
      else if (y - size >= 0){
	for (i = 0; i < size; i++)
	  game[z][x][y--] = id;
      }
    }
}

int VerifBoat(int game[ZMAX][XMAX][YMAX], int z, int x, int y, char sens, int size)
{
  int i = 0;

  x = correcrand(x);
  y = correcrand(y);
  if (sens != SENSV && sens != SENSH)
    sens = SENSV;
  if (sens == SENSV)
    {
      if (x + size < XMAX){
	for (i = 0; i < size; i++)
	  if (game[z][x][y] > 0)
	    return -1;
      }
      else if (x - size >= 0){
	for (i = 0; i < size; i++)
	  if (game[z][x][y] > 0)
	    return -1;
      }
    }
  else if (sens == SENSH)
    {
      if (y + size < YMAX){
	for (i = 0; i < size; i++)
	  if (game[z][x][y] > 0)
	    return -1;
      }
      else if (y - size >= 0){
	for (i = 0; i < size; i++)
	  if (game[z][x][y] > 0)
	    return -1;
      }
    }
  return 0;
}

/*
** Fonction principale du placement de bateau
*/
void place_boat(int game[ZMAX][XMAX][YMAX], int id, int ia, int x, int y, char sens)
{
  if (id == ID_CORVETTE)
    place_all(game, ia, x, y, sens, SIZE_CORVETTE, id);
  else if (id == ID_DESTROYER)
    place_all(game, ia, x, y, sens, SIZE_DESTROYER, id);
  else if (id == ID_CROISEUR)
    place_all(game, ia, x, y, sens, SIZE_CROISEUR, id);
  else if (id == ID_PORTEAVION)
    place_all(game, ia, x, y, sens, SIZE_PORTEAVION, id);
}

/*
** Place les bateau de L'IA en random
*/
void place_Rboat(int game[ZMAX][XMAX][YMAX], int ia)
{
  int x = 0;
  int y = 0;
  int a = 0;
  int r = 0;
  int rplus = TEMPS_CHARGEMENT * 42;
  char sens = SENSV;

  if (ia == 1)
    {
      CapRandom();
      rplus = (XMAX * YMAX * TEMPS_CHARGEMENT) + 1;
      my_printf("J'ai place mes bateaux, que la force soit avec moi !!!! \n");
    }
  srand(time(NULL));
  for(a = 0; a < NB_CORVETTE; a++)
    {
      r = (rand() * rand() * rplus) % 2;
      x = (rand() * rand() * rplus) % XMAX;
      y = (rand() * rplus) % YMAX;
      if (r == 0)
	sens = SENSH;
      else
	sens = SENSV;
      if (VerifBoat(game, ia, x, y, sens, SIZE_CORVETTE) == 0)
	place_all(game, ia, x, y, sens, SIZE_CORVETTE, 1);
      else
	a--;
    }
  my_printf("%d Corvette placer\n", a + 1);
  for(a = 0; a < NB_DESTROYER; a++)
    {
      r = (rand() * rplus)%2;
      x = (rand() * rplus) % XMAX;
      y = (rand() * (rplus % YMAX)) % YMAX;
      if (r == 0)
	sens = SENSH;
      else
	sens = SENSV;
      if (VerifBoat(game, ia, x, y, sens, SIZE_DESTROYER) == 0)
	place_all(game, ia, x, y, sens, SIZE_DESTROYER, 2);
      else
	a--;
    }
  my_printf("%d Destroyer placer\n", a + 1);
  for(a = 0; a < NB_CROISEUR; a++)
    {
      r = (rand() * time(NULL) * rplus)%2;
      x = ((rand() * time(NULL)) % rplus) % XMAX;
      y = ((rand() * time(NULL)) - rplus) % YMAX;
      if (r == 0)
	sens = SENSH;
      else
	sens = SENSV;
      if (VerifBoat(game, ia, x, y, sens, SIZE_CROISEUR) == 0)
	place_all(game, ia, x, y, sens, SIZE_CROISEUR, 3);
      else
	a--;
    }
  my_printf("%d Croiseur placer\n", a + 1);
  for(a = 0; a < NB_PORTEAVION; a++)
    {
      r = (rand() * (rplus % XMAX))%2;
      x = (rand() * rplus) % XMAX;
      y = (rand() * (rand() % rplus)) % YMAX;
      if (r == 0)
	sens = SENSH;
      else
	sens = SENSV;
      if (VerifBoat(game, ia, x, y, sens, SIZE_PORTEAVION) == 0)
	place_all(game, ia, x, y, sens, SIZE_PORTEAVION, 4);
      else
	a--;
    }
  my_printf("%d Porte-avion placer\n", a + 1);
}
