/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
double ara[1000005];
 
void ara_gen()
{
    ara[0] = 0;
    for(int i=1; i<=1000000; i++) {
        ara[i] = ara[i-1] + log(i);
    }
}
 
int main()
{
    int tc, n, i, j, k, x, y, z, cnt;
    double b;
 
    ara_gen();
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n >> b;
 
        int cnt = ara[n]/log(b) + 1;
 
        printf("Case %d: %d\n", i+1, cnt);
    }
 
    return 0;
}
