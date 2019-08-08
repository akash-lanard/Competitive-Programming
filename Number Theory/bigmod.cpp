#include <bits/stdc++.h>
using namespace std;

int bigmod(int a, int b, int M)  {   //may require long long, check input range                      
    if(b==0) return 1%M;
    int x = bigmod(a, b/2, M);
    x = (x*x)%M;    //may overflow
    if(b%2==1) x = (x*a)%M;
    return x;
}

int main() {
    int a, b, M;
    while(1) {
        cin >> a >> b >> M;
        if(a==0 && b==0 && M==0) break;
        cout << bigmod(a, b, M) << endl;
    }
    return 0;
}
