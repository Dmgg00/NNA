void print_map(int arr[n][m], robot object);
void generate_map(int a0[n][m],robot target);

void generate_map(int a0[n][m], robot target)
{

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
            else if (prob(22))
            {
                a0[i][j] = -1;
            }
            else
            {
                a0[i][j] = 0;
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
            else if (arr[i][j] > 1)
            {
                printf("1");
            }
            else if (arr[i][j]==0)
            {
                printf("⬜");
            }
        }
        printf("\n");
    }
}