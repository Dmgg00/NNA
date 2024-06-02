void print_map(int arr[n][m]);
void generate_map(int a0[n][m]);

void generate_map(int a0[n][m])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == (n - 1) || j == (m)-1 || i == 0 || j == 0)
            {
                a0[i][j] = -1;
            }
            else if (prob(7.1416))
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

void print_map(int arr[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                printf(" ");
            }
            else if (arr[i][j] == -1)
            {
                printf("▩");
            }
            else if (arr[i][j] > 1)
            {
                printf("1");
            }
            else if (arr[i][j]==1)
            {
                printf("🤖");
            }
        }
        printf("\n");
    }
}