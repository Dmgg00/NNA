void neuro_net(double w[21], double in[5], int out[2]);

void neuro_net(double w[21], double in[5], int out[2])
{
    int j = 0;
    while (j < 24)
    {
        printf(" %f ", w[j]);
        j++;
    }

    int i = 0;
    double neuronas[7];
    for (int j = 0; j < 7; j++)
    {
        neuronas[j] = 0;
    }

    while (i < 5)
    {
        neuronas[0] = neuronas[0] + (w[i] * in[i]);
        neuronas[1] = neuronas[1] + (w[i + 5] * in[i]);
        i++;
    }

    double sig[3];

    sig[0] = sigmoide(neuronas[0]);
    sig[1] = sigmoide(neuronas[1]);
    sig[2] = sigmoide(neuronas[2]);

    int k = 0;

    while (k < 3)
    {
        neuronas[3] = neuronas[3] + (w[k + 12] * sig[k]);
        neuronas[4] = neuronas[4] + (w[k + 15] * sig[k]);
        neuronas[5] = neuronas[5] + (w[k + 18] * sig[k]);
        neuronas[6] = neuronas[6] + (w[k + 21] * sig[k]);

        k++;
    }

    out[0] = piso(neuronas[3]);
    out[1] = piso(neuronas[4]);

    // printf("\n neu 1 = %f, neu 2 = %f, neu 3 = %f\n", neuronas[0], neuronas[1], neuronas[2]);
    // printf("\nsig 1 = %f, sig 2 = %f, sig 3 = %f\n", sig[0], sig[1], sig[2]);
    //printf("\n neu 4 = %f, neu 5 = %f, neu 6 = %f, neu 7 = %f\n", neuronas[3], neuronas[4], neuronas[5], neuronas[6]);
    printf("\n(%d,%d)\n", out[0], out[1]);
}