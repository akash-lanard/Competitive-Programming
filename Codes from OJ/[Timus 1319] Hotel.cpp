/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, k, x[10005], y[10005], sq_n, sum_n, num1, num2, ara[102][102];

    cin >> n;

    for(i=0, num1=1, num2=1; i<2*n-1; i++) {
        if(i<n) {
            for(j=n-i; j<=n; j++) {
                x[num1] = j;
                num1++;
            }
            for(j=1; j<=i+1; j++) {
                y[num2] = j;
                num2++;
            }
        }
        else {
            for(j=1; j<=2*n-i-1; j++) {
                x[num1] = j;
                num1++;
            }
            for(j=i-n+2; j<=n; j++) {
                y[num2] = j;
                num2++;
            }
        }
    }

    for(i=1; i<=n*n; i++) {
        ara[y[i]][x[i]] = i;
    }

    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if(j!=1) printf(" ");
            printf("%d", ara[i][j]);
        }
        printf("\n");
    }

    return 0;
}
