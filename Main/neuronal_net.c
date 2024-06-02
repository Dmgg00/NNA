#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define n 50 //map height
#define m 100 // map large
#define n_robots 50

// Josh Bongard. Xenobots

typedef struct
{
    int cord_i, cord_j;
    int fitness;
    double fenotipo[12];
    int genotipo[96];
} robot;

#include "../Functions/f_cuerpo.h"
#include "../Functions/f_other.h"
#include "../Functions/f_map.h"

int main(void)
{
    /**********************************************************************/
    /*Generamos los mapas y cada robot colocandolo en el mapa generado en 
    este ciclo y guardandolo en una matriz de robots*/
    srand(time(NULL));
    robot Robots[n_robots];
    for (int i = 0; i < n_robots; i++)
    {
        robot nuevo;
        nuevo.cord_i = (rand() % n-1)+1;
        nuevo.cord_j = (rand() % m-1)+1;
        Robots[i] = nuevo;
        int map[n][m];
        generate_map(map);
        map[Robots[i].cord_i][Robots[i].cord_j]=1;
        print_map(map);
    }

    /**********************************************************************/

    return 0;
}