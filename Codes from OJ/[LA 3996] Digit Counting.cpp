/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        int n;
        scanf("%d", &n);
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        for(int j=1; j<=n; j++) {
            int temp = j;
            while(temp>0) {
                int rem = temp%10;
                cnt[rem]++;
                temp /= 10;
            }
        }
        for(int j=0; j<10; j++) {
            if(j==0) printf("%d", cnt[j]);
            else printf(" %d", cnt[j]);
        }
        printf("\n");
    }
    return 0;
}
