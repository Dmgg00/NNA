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