#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#define n 10 // map height
#define m 20 // map large
#define n_robots 50

// Josh Bongard. Xenobots

typedef struct
{
    int cord_i, cord_j;
    int fitness;
    double fenotipo[24];
    double sensor_valors[4];
} robot;

#include "../Functions/f_cuerpo.h"
#include "../Functions/f_other.h"
#include "../Functions/f_map.h"
#include "../Functions/f_neuro.h"

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
        nuevo.cord_i = (rand() % (n - 2)) + 1;
        nuevo.cord_j = (rand() % (m - 2)) + 1;
        Robots[i] = nuevo;
        if (i == 0)
        {
            for (int iterator_firs_weigh = 0; iterator_firs_weigh < 24; iterator_firs_weigh++)
            {
                nuevo.fenotipo[iterator_firs_weigh] = (double)(rand() % 15) / (double)15;
            }
        }

        int map[n][m];
        generate_map(map, Robots[i]);
        int movimientos_robot = 0;
        while (movimientos_robot < 300)
        {
            //system("clear");
            printf("ciclo %d\n", movimientos_robot);
            print_map(map, Robots[i]);
            printf("\n(%d,%d)\n", Robots[i].cord_i, Robots[i].cord_j);
            Sensor(Robots[i].cord_i, Robots[i].cord_j, map, Robots[i].sensor_valors);
            // printf("\nsens 1 = %f, sens 2 = %f, sens 3 = %f, sens 4 = %f\n", Robots[i].sensor_valors[0],Robots[i].sensor_valors[1],Robots[i].sensor_valors[2],Robots[i].sensor_valors[3]);
            int arr[4];
            neuro_net(nuevo.fenotipo, Robots[i].sensor_valors, arr);
            //  printf("\n out 1 = %d, out 2 = %d, out 3 = %d, out 4 = %d\n", arr[0], arr[1], arr[2], arr[3]);
            Robots[i] = motores_v(Robots[i], arr);
            if (map[Robots[i].cord_i][Robots[i].cord_j] == -1)
            {
                break;
            }
            Robots[i] = motores_h(Robots[i], arr);
            if (map[Robots[i].cord_i][Robots[i].cord_j] == -1)
            {
                break;
            }
            // printf("\n(%d,%d)\n", Robots[i].cord_i, Robots[i].cord_j);
            // print_map(map, Robots[i]);
            movimientos_robot++;
            sleep(2);
        }
        printf("\nmurio, vivio %d ciclos \n", movimientos_robot);
        sleep(2);
    }

    /**********************************************************************/

    return 0;
}