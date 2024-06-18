#define EULER_NUMBER 2.71828

int prob(double percent);
void Bin_to_dex(double dex[14], int bin[56]);
int piso(double x);
void Dex_to_Bin(double dex[14], int Bin[56]);

int prob(double percent) // recordar que esta funcion usa -lm para compilar
{
    double a = 100.9999;
    double x = fmod((double)rand(), a);
    if (x < percent)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int piso(double x)
{
    if (x < (double)0)
    {
        return -1;
    }

    if (x >= (double)0)
    {
        if (x >= (double)0.5)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void Dex_to_Bin(double dex[14], int Bin[56])
{
    int j=0;
    while (j<14)
    {
        dex[j]=dex[j]*15;
        j++;
    }
    
    int i = 0;
    while (i < 56)
    {
        Bin[i] = (int)(dex[i/4]) % (2);
        dex[i / 4] = (dex[i/4] - Bin[i])/2;
        i++;
    }
}

void Bin_to_dex(double dex[14], int bin[56])
{
    int i=55;
    while (i>=3)
    {
        dex[i/4]= (bin[i]*8) + (bin[i-1]*4) + (bin[i-2]*2) + (bin[i-3]*1);
        dex[i/4]= dex[i/4]/(double)15;
        i=i-4;
    }
}