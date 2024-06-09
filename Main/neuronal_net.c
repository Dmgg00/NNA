#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
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
    int sensor_valors[4];
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
    
        robot nuevo;
        nuevo.cord_i = (rand() % n-1)+1;
        nuevo.cord_j = (rand() % m-1)+1;
        Robots[0] = nuevo;
        int map[n][m];
        generate_map(map);
        map[Robots[0].cord_i][Robots[0].cord_j]=1;
        print_map(map);
        printf("\n(%d,%d)\n", Robots[0].cord_i, Robots[0].cord_j);
        Sensor(Robots[0].cord_i,Robots[0].cord_j, map , Robots[0].sensor_valors);

    /**********************************************************************/

    return 0;
}