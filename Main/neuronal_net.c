#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#define n 20 // map height
#define m 20 // map large
#define n_robots 50

// Josh Bongard. Xenobots

typedef struct
{
    int cord_i, cord_j;
    int fitness;
    double fenotipo[14];
    double sensor_valors[5];
} robot;

typedef struct
{
    int i, j;
} coords;

#include "../Functions/f_cuerpo.h"
#include "../Functions/f_other.h"
#include "../Functions/f_map.h"
#include "../Functions/f_neuro.h"
#include "../Functions/f_gen.h"

int main(void)
{
    /**********************************************************************/
    /*Generamos los mapas y cada robot colocandolo en el mapa generado en
    este ciclo y guardandolo en una matriz de robots*/
    srand(time(NULL));
    FILE * pfile;
    pfile= fopen("gen.txt", "w");
    int generaciones = 0;
    robot Robots[n_robots];
    while (generaciones < 1)
    {
        robot nuevo;
        nuevo.cord_i = (rand() % (n - 2)) + 1;
        nuevo.cord_j = (rand() % (m - 2)) + 1;

        if (generaciones == 0)
        {
            for (int iterator_firs_weigh = 0; iterator_firs_weigh < 14; iterator_firs_weigh++)
            {
                nuevo.fenotipo[iterator_firs_weigh] = (double)(rand() % 15) / (double)15;
            }
        }
        for (int i = 0; i < n_robots; i++)
        {
            Robots[i] = nuevo;

            int map[n][m];
            generate_map(map, Robots[i]);
            coords origen, posicion_previa;
            int pasos;
            int movimientos_robot = 0;
            int out[2];

            while (movimientos_robot < 100)
            {

                if (movimientos_robot == 0)
                {
                    origen.i = Robots[i].cord_i;
                    origen.j = Robots[i].cord_j;
                }
                posicion_previa.i = Robots[i].cord_i;
                posicion_previa.j = Robots[i].cord_j;

                system("clear");
                //  printf("ciclo %d\n", movimientos_robot);
                print_map(map, Robots[i]);
                // printf("\n(%d,%d)\n", Robots[i].cord_i, Robots[i].cord_j);
                Sensor(Robots[i].cord_i, Robots[i].cord_j, map, Robots[i].sensor_valors);
                // printf("\nsens 1 = %f, sens 2 = %f, sens 3 = %f, sens 4 = %f\n", Robots[i].sensor_valors[0],Robots[i].sensor_valors[1],Robots[i].sensor_valors[2],Robots[i].sensor_valors[3]);

                neuro_net(nuevo.fenotipo, Robots[i].sensor_valors, out);
                //  printf("\n out 1 = %d, out 2 = %d, out 3 = %d, out 4 = %d\n", arr[0], arr[1], arr[2], arr[3]);

                Robots[i] = motores(Robots[i], out);

                if (map[Robots[i].cord_i][Robots[i].cord_j] == -1)
                {
                    break;
                }

                /**********************************************************************/
                /*Configuracion del Fitnes*/

                if (Robots[i].cord_i != posicion_previa.i || Robots[i].cord_j != posicion_previa.j)
                {
                    pasos++;
                }
                Robots[i].fitness = Robots[i].fitness + map[Robots[i].cord_i][Robots[i].cord_j];

                /**********************************************************************/

                // printf("\n(%d,%d)\n", Robots[i].cord_i, Robots[i].cord_j);
                // print_map(map, Robots[i]);
                movimientos_robot++;
                usleep(50000);
            }
            int desplazamiento, distancia;
            desplazamiento = sqrt(((origen.i - Robots[i].cord_i) * (origen.i - Robots[i].cord_i)) + ((origen.j - Robots[i].cord_j) * (origen.j - Robots[i].cord_j)));
            distancia = desplazamiento + pasos;
            Robots[i].fitness = Robots[i].fitness + distancia;
            desplazamiento =0;
            pasos=0;

            fprintf(pfile," gen %d robot %d fit %d dir %p \n", generaciones, i, Robots[i].fitness, &Robots[i]);
            // printf("\nsu fitnes fue %d\n", Robots[i].fitness);
            // printf("\n/**********************************************************************/\nmurio, vivio %d ciclos \n/**********************************************************************/\n", movimientos_robot);

        }
        // for (int i = 0; i < n_robots; i++)
        // {
        //     printf(" gen %d robot %d fit %d dir %p \n", generaciones, i, Robots[i].fitness, &Robots[i]);
        // }
        
            //cruce(Robots);
        generaciones++;
    }

    /**********************************************************************/

    return 0;
}