/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int ara1[100000];
int ara2[100000];

void aragen()
{
    ara1[0] = 0;
    ara1[1] = 1;
    for(int i=1; 2*i<100000;i++) {
        ara1[2*i] = ara1[i];
        ara1[2*i+1] = ara1[i] + ara1[i+1];
    }
    int mx = 0;
    for(int i=0; i<100000; i++) {
        if(ara1[i]>mx) mx = ara1[i];
        ara2[i] = mx;
    }
}
int main()
{
    int n;
    aragen();
    while(1) {
        scanf("%d", &n);
        if(n==0) break;
        cout << ara2[n] << endl;
    }

    return 0;
}
