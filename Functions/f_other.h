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

int piso(double x)
{
    if (x>= (double)1.09)
    {
        return 1;
    } else {
        return 0;
    }    
}
