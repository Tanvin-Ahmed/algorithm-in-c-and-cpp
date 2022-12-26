#include <stdio.h>
#include <string.h>

const int N = 99;

int max(int a, int b)
{
    return a > b ? a : b;
}

int lcs(char x[], char y[], int m, int n, int dp[][N])
{
    if (m == 0 || n == 0)
        return 0;

    if (dp[m - 1][n - 1] != -1)
        return dp[m - 1][n - 1];

    if (x[m - 1] == y[n - 1])
        dp[m - 1][n - 1] = 1 + lcs(x, y, m - 1, n - 1, dp);
    else
        dp[m - 1][n - 1] = max(lcs(x, y, m - 1, n, dp), lcs(x, y, m, n - 1, dp));

    return dp[m - 1][n - 1];
}

int main()
{
    char x[] = "AGGTAB";
    char y[] = "GXTXAYB";

    int m = strlen(x);
    int n = strlen(y);

    int dp[m][N];

    memset(dp, -1, sizeof(dp));

    printf("Length of LCS is %d\n", lcs(x, y, m, n, dp));

    return 0;
}

// complexity Analysis :
// Time Complexity : O(N *M),
// where N and M are lengths of the first and second string respectively.
// Auxiliary Space : (N *M)
