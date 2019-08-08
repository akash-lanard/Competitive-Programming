#include <bits/stdc++.h>
using namespace std;

long long moduloMultiplication(long long a, long long b, long long m) {
    long long res = 0;
    a %= m;

    while(b) {
        if(b & 1) {
            res = (res + a) % m;
        }
        a = (2*a)%m;
        b /= 2;
    }

    return res;
}

int main () {

    long long a = 10123465234878998, b = 65746311545646431, m = 10005412336548794;
    //long long res = (a*b)%m;
    long long res = moduloMultiplication(a, b, m);

    cout << "a = " << a << ", b = " << b << ", m = " << m << ", (a*b)%m = " << res << endl;

    return 0;
}
