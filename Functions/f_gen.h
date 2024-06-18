void cruce(robot Robots[n_robots]);

void cruce(robot Robots[n_robots])
{
    robot Fathers[25];
    robot Temp;
    int robots_selected = 0;
    int fit_t = 0;
    int j = 0;
    int i=0;
    int k=0;
    while (j < n_robots)
    {
        fit_t = fit_t + Robots[j].fitness;
        //printf("\nfit %p\n", &Robots[j]);
        j++;
    }
    printf("\nfit t = %d\n", fit_t);

    while (1)
    {
        if (robots_selected == 24)
        {
            break;
        }
        //printf("\nfit %p\n", &Robots[i]);
        //printf("\n%f\n",(double)(Robots[i].fitness)/(double)fit_t);
        if (prob((double)(Robots[i].fitness) / (double)fit_t))
        {
            Fathers[robots_selected] = Robots[i];
            printf("dir %p ",&Robots[i]);
            robots_selected++;
        }
        i++;
        i=i%50;
    }

    while (k<25)
    {
        printf("%p ", &Fathers[k]);
        k++;
    }
    
}