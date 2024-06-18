void neuro_net(double w[14], double in[5], int out[2]);

void neuro_net(double w[14], double in[5], int out[2])
{

    int i = 0;
    double neuronas[4];
    for (int j = 0; j < 4; j++)
    {
        neuronas[j] = 0;
    }

    while (i < 5)
    {
        neuronas[0] = neuronas[0] + (w[i] * in[i]);
        neuronas[1] = neuronas[1] + (w[i + 5] * in[i]);
        i++;
    }


    neuronas[0] = piso(neuronas[0]);
    neuronas[1] = piso(neuronas[1]);

    int k = 0;
    while (k < 3)
    {
        neuronas[2]=neuronas[2]+(neuronas[k]*w[k+10]);
        neuronas[3]=neuronas[3]+(neuronas[k]*w[k+12]);
        k++;
    }

    out[0] = piso(neuronas[2]);
    out[1] = piso(neuronas[3]);

    // printf("\n");
    // for (int i = 0; i < 14; i++)
    // {
    //     printf("peso %d=%f ",i,w[i]);
    // }
    // printf("\n neu 0 = %f, neu 1 = %f\n", neuronas[0], neuronas[1]);
    // printf("\n neu 2 = %f, neu 3 = %f\n", neuronas[2], neuronas[3]);
    // printf("\n(%d,%d)\n", out[0], out[1]);
}