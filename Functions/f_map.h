void print_map(int arr[n][m], robot object);
void generate_map(int a0[n][m],robot target);

void generate_map(int a0[n][m], robot target)
{
    int luz_i,luz_j;
    luz_i=(rand() % (n - 2)) + 1;
    luz_j=(rand() % (m - 2)) + 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == (n - 1) || j == (m)-1 || i == 0 || j == 0)
            {
                a0[i][j] = -1;
            }
            else if (i==target.cord_i&&j==target.cord_j)
            {
                a0[i][j]=0;
            }
            else if (i==luz_i&&j==luz_j)
            {
                a0[i][j]=1;
            }
            else if (prob(8))
            {
                a0[i][j] = -1;
            }
            else
            {
                a0[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a0[i][j]==0)
            {
                int diametro = sqrt(((j - luz_j) * (j - luz_j)) + ((i - luz_i) * (i - luz_i)));
                if (diametro <= 1)//el numerito es que tan grande es el randiante 
                {
                    a0[i][j] = 1;
                }
            }
            
        }
    }    
}

void print_map(int arr[n][m], robot object)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i==object.cord_i&&j==object.cord_j)
            {
                printf("🟥");
            }
            else if (arr[i][j] == -1)
            {
                printf("⬛");
            }
            else if (arr[i][j] == 1)
            {
                printf("🟧");
            }
            else if (arr[i][j]==0)
            {
                printf("⬜");
            }
        }
        printf("\n");
    }
}