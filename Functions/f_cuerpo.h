void mover_horizontal(robot objetivo, int movimiento);
void mover_vertical(robot objetivo, int movimiento);

void mover_horizontal(robot objetivo, int movimiento)
{   
    /*El movimiento debe estar entre -1 y 1 tomandolos en cuenta
    -1 es un movimiento a la izquierda, 1 a la derecha y 0 es la
    ausencia de movimiento */
    objetivo.cord_j+=movimiento;
}

void mover_vertical(robot objetivo, int movimiento)
{   
    /*El movimiento debe estar entre -1 y 1 tomandolos en cuenta
    -1 es un movimiento a la arriba, 1 a la abajo y 0 es la
    ausencia de movimiento */
    objetivo.cord_i+=movimiento;
}

int Sensor(int object_coord_n,int object_coord_m, int map[n][m], int sensor_return[4])
{
    if (map[object_coord_n][object_coord_m-1]=-1)
    {
        sensor_return[0]=0;
    }
    else if (map[object_coord_n][object_coord_m-2]=-1)
    {
        sensor_return[0]=1;
    }
    if (map[object_coord_n+1][object_coord_m]=-1)
    {
        sensor_return[1]=0;
    }
    else if (map[object_coord_n+2][object_coord_m]=-1)
    {
        sensor_return[1]=1;
    }
}