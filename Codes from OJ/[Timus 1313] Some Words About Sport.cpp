/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ara[101][101], i, j, k, r[10001], c[10001], x, y, z;

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &ara[i][j]);
        }
    }

    for(i=0, x=0, y=0; i<(2*n)-1; i++) {
        if(i<n) {
            for(j=i; j>=0; j--) {
                r[x] = j;
                x++;
            }
            for(j=0; j<=i; j++) {
                c[y] = j;
                y++;
            }
        }
        else {
            for(j=n-1; j>=i+1-n; j--) {
                r[x] = j;
                x++;
            }
            for(j=i+1-n; j<=n-1; j++) {
                c[y] = j;
                y++;
            }
        }
    }

    for(i=0; i<n*n; i++) {
        if(i==0) printf("%d", ara[r[i]][c[i]]);
        else printf(" %d", ara[r[i]][c[i]]);
    }

    return 0;
}
