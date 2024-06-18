void Sensor(int object_coord_n, int object_coord_m, int map[n][m], double sensor_return[5]);
robot motores(robot target, int señales[2]);

void Sensor(int object_coord_n, int object_coord_m, int map[n][m], double sensor_return[5])
{

    // printf("\n(%d,%d)\n", object_coord_n, object_coord_m);
    sensor_return[0] = -1;
    sensor_return[1] = -1;
    sensor_return[2] = -1;
    sensor_return[3] = -1;
    int t = 0;
    int Sensors_ready = 0;

    while (Sensors_ready < 4)
    {
        if (map[object_coord_n - t - 1][object_coord_m] == -1)
        {
            if (sensor_return[0] == -1)
            {
                Sensors_ready++;
                sensor_return[0] = t;
            }
        }

        if (map[object_coord_n + t + 1][object_coord_m] == -1)
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
    sensor_return[0] = sensor_return[0] / t;
    sensor_return[1] = sensor_return[1] / t;
    sensor_return[2] = sensor_return[2] / t;
    sensor_return[3] = sensor_return[3] / t;
    sensor_return[4] = (map[object_coord_n][object_coord_m])*-1;

    // printf("\n sesor i arr = %f\n", sensor_return[0]);
    // printf("\n sesor i abaj = %f\n", sensor_return[1]);
    // printf("\n sesor j der = %f\n", sensor_return[2]);
    // printf("\n sesor j izqu = %f\n", sensor_return[3]);
}

robot motores(robot target, int señales[2])
{
    robot modificado = target;

    if (señales[0] == 1 && señales[1]==1)
    {
        modificado.cord_i--;
    }

    if (señales[0] == 1 && señales[1]==0)
    {
        modificado.cord_j--;
    }

    if (señales[0] == 0 && señales[1]==1)
    {
        modificado.cord_j++;
    }

    if (señales[0] == 0 && señales[1]==0)
    {
        modificado.cord_i--;
    }

    return modificado;
}
