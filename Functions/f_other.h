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