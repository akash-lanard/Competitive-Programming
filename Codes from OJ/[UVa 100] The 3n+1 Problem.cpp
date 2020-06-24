/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c, d;

    while(scanf("%lld %lld", &a, &b)==2) {
        if(a<=b) {
            c = a;
            d = b;
        }
        else {
            c = b;
            d = a;
        }
        long long mx=0, num, cnt;

        for(long long i=c; i<=d; i++) {
            num = i;
            cnt = 0;
            while(1) {
                cnt++;
                if(num==1) break;
                if(num%2) num = 3*num + 1;
                else num /= 2;
            }
            if(cnt>mx) mx = cnt;
        }
        printf("%lld %lld %lld\n", a, b, mx);
    }
    return 0;
}
