#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int ret = n;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            //i is a prime dividing n
            while(n%i==0) {
                //divide all factors of i
                n /= i;
            }
            //same as: ret * (1 - 1/p)
            ret -= ret/i;
        }
    }
    if(n>1) {
        //there can be only one prime greater
        //that sqrt(n) that divides n
        ret -= ret/n;
    }
    return ret;
}

int main()
{
    int n;
    while(1) {
        cin >> n;
        if(n==0) break;
        cout << phi(n) << endl;
    }
    return 0;
}
