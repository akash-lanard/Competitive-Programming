#include <bits/stdc++.h>
using namespace std;

int numOfDiv(int n)
{
    int cnt = 0, sq = sqrt(n);
    for(int i=1; i<=sq; i++) {
        if(n%i==0) {
            if(n/i == i) cnt++;
            else cnt+=2;
        }
    }
    return cnt;
}
