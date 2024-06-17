#define EULER_NUMBER 2.71828

double sigmoide(double x);
int prob(double percent);

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

double sigmoide(double x) 
{
    return (1 / (1 + pow(EULER_NUMBER, -x)));
}

double mod_sigmoide(double x)
{
    return ((1 / ((double)0,5 + pow(EULER_NUMBER, -x)))-1);
}

int piso(double x)
{
    if (x>= (double)1)
    {
        return 1;
    } else {
        return 0;
    }    
}
