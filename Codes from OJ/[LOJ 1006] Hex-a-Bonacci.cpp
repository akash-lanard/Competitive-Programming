/// Verdict: AC

#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, n, t, i, j, dp[10001], x;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &n);
        dp[0] = a%10000007;
        dp[1] = b%10000007;
        dp[2] = c%10000007;
        dp[3] = d%10000007;
        dp[4] = e%10000007;
        dp[5] = f%10000007;
        x = dp[0] + dp[1] + dp[2] + dp[3] + dp[4] + dp[5];
        for (j = 6; j <= 10000; j++) {
            dp[j] = x%10000007;
            x = x + dp[j] - dp[j-6];
        }
        printf("Case %d: %d\n", i+1, dp[n]);
    }
    return 0;
}
