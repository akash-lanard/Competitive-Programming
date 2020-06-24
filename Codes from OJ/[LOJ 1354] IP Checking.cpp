/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int binToDec(int n)
{
    int p2 = 1;
    int ans=0;
    while(n!=0) {
        int p = n%10;
        ans += p*p2;
        p2 *= 2;
        n /= 10;
    }
    return ans;
}
 
int main()
{
    int tc, a[4], b[4], p, q, r, s, i, j, flag;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
        scanf("%d.%d.%d.%d", &b[0], &b[1], &b[2], &b[3]);
 
        b[0] = binToDec(b[0]);
        b[1] = binToDec(b[1]);
        b[2] = binToDec(b[2]);
        b[3] = binToDec(b[3]);
 
        flag = 1;
        for(j=0; j<4; j++) {
            if(a[j]!=b[j]) {
                flag = 0;
                break;
            }
        }
 
        if(flag) {
            printf("Case %d: Yes\n", i+1);
        }
        else {
            printf("Case %d: No\n", i+1);
        }
    }
    return 0;
}
