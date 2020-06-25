/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i=0; ;i++) {
        int n, m, c;
        scanf("%d %d %d", &n, &m, &c);
        if(n==0 && m==0 && c==0) break;
        int ara[n+5];
        for(int j=1; j<=n; j++) {
            scanf("%d", &ara[j]);
        }
        int mark[n+5];
        int seq[m+5];
        memset(mark, 0, sizeof(mark));
        for(int j=1; j<=m; j++) {
            scanf("%d", &seq[j]);
        }

        int sum=0;
        int flag=1;
        int mx=0;
        for(int j=1; j<=m; j++) {
            if(!mark[seq[j]]) {
                sum += ara[seq[j]];
                if(sum>mx) mx = sum;
                mark[seq[j]] = 1;
                if(sum>c) {
                    flag = 0;
                    break;
                }
            }
            else {
                sum -= ara[seq[j]];
                mark[seq[j]] = 0;
            }
        }

        printf("Sequence %d\n", i+1);
        if(!flag) printf("Fuse was blown.\n\n");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", mx);
    }
    return 0;
}
