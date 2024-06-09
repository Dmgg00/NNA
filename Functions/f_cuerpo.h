void mover_horizontal(robot objetivo, int movimiento);
void mover_vertical(robot objetivo, int movimiento);

void mover_horizontal(robot objetivo, int movimiento)
{
    /*El movimiento debe estar entre -1 y 1 tomandolos en cuenta
    -1 es un movimiento a la izquierda, 1 a la derecha y 0 es la
    ausencia de movimiento */
    objetivo.cord_j += movimiento;
}

void mover_vertical(robot objetivo, int movimiento)
{
    /*El movimiento debe estar entre -1 y 1 tomandolos en cuenta
    -1 es un movimiento a la arriba, 1 a la abajo y 0 es la
    ausencia de movimiento */
    objetivo.cord_i += movimiento;
}

void Sensor(int object_coord_n, int object_coord_m, int map[n][m], int sensor_return[4])
{

    printf("\n(%d,%d)\n", object_coord_n, object_coord_m);
    sensor_return[0] = -1;
    sensor_return[1] = -1;
    sensor_return[2] = -1;
    sensor_return[3] = -1;
    int t = 0;
    int Sensors_ready = 0;

    while (Sensors_ready < 4)
    {
        if (map[object_coord_n + t + 1][object_coord_m] == -1)
        {
            if (sensor_return[0] == -1)
            {
                Sensors_ready++;
                sensor_return[0] = t;
            }
        }

        if (map[object_coord_n - t - 1][object_coord_m] == -1)
        {
            if (sensor_return[1] == -1)
            {
                Sensors_ready++;
                sensor_return[1] = t;
            }
        }

        if (map[object_coord_n][object_coord_m + 1 + t] == -1)
        {
            if (sensor_return[2] == -1)
            {
                Sensors_ready++;
                sensor_return[2] = t;
            }
        }

        if (map[object_coord_n][object_coord_m - t - 1] == -1)
        {
            if (sensor_return[3] == -1)
            {
                Sensors_ready++;
                sensor_return[3] = t;
            }
        }
        t++;
    }
    printf("\n sesor i arr = %d\n", sensor_return[0]);
    printf("\n sesor i abaj = %d\n", sensor_return[1]);
    printf("\n sesor j der = %d\n", sensor_return[2]);
    printf("\n sesor j izqu = %d\n", sensor_return[3]);
}