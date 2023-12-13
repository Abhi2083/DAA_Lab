<<<<<<< Updated upstream
#include <stdio.h>
#include <limits.h>

int M[100][100];
int S[100][100];

void printOptimalParenthesis(int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        printOptimalParenthesis(i, S[i][j]);
        printOptimalParenthesis(S[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n)
{
    int i, j, k, L, q;
    for (i = 1; i <= n; i++)
        M[i][i] = 0;

    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            M[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < M[i][j])
                {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    int n, i, r, c;
    int p[100];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter row and col size of A%d: ", i);
        scanf("%d %d", &r, &c);
        if (i > 1 && p[i - 1] != r)
        {
            printf("Invalid dimensions.\n");
            return 1;
        }
        p[i - 1] = r;
        p[i] = c;
    }

    matrixChainOrder(p, n);

    printf("\nM Table:\n");
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", S[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal parenthesization: ");
    printOptimalParenthesis(1, n);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", M[1][n]);
    return 0;
=======
#include <stdio.h>
#include <limits.h>

int M[100][100];
int S[100][100];

void printOptimalParenthesis(int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        printOptimalParenthesis(i, S[i][j]);
        printOptimalParenthesis(S[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n)
{
    int i, j, k, L, q;
    for (i = 1; i <= n; i++)
        M[i][i] = 0;

    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            M[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < M[i][j])
                {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    int n, i, r, c;
    int p[100];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter row and col size of A%d: ", i);
        scanf("%d %d", &r, &c);
        if (i > 1 && p[i - 1] != r)
        {
            printf("Invalid dimensions.\n");
            return 1;
        }
        p[i - 1] = r;
        p[i] = c;
    }

    matrixChainOrder(p, n);

    printf("\nM Table:\n");
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", S[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal parenthesization: ");
    printOptimalParenthesis(1, n);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", M[1][n]);
    return 0;
>>>>>>> Stashed changes
}