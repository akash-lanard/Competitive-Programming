#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL mulmod ( LL a, LL b, LL m ) {
    if ( a < b ) swap ( a, b );
    LL res = 0, x = a;
    while ( b > 0 ) {
        if ( b & 1 ) {
            res = res + x;
            if ( res >= m ) res -= m;
        }
        x = x * 2;
        if ( x >= m ) x -= m;
        b >>= 1;
     }
     return res % m;
}

inline LL bigmod ( LL a, LL p, LL m ) {
    LL res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = mulmod(res, x, m);
        x = mulmod(x, x, m); p >>= 1; /// For bigmod2 multiply here using mulmod
    }
    return res;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool millerTest(LL d, LL n) {
    LL a = 2 + rng() % (n-4);
    LL x = bigmod(a, d, n);

    if(x==1 || x==n-1) {
        return true;
    }

    while(d != n-1) {
        x = mulmod(x, x, n);
        d *= 2;

        if(x==1) return false;
        if(x== n-1) return true;
    }

    return false;
}

bool isPrime(LL n, LL k) {
    if(n<=1 || n==4) return false;
    if(n<=3) return true;

    LL d = n - 1;
    while(d%2==0) {
        d /= 2;
    }

    for(LL i=0; i<k; i++) {
        if(!millerTest(d, n)) return false;
    }

    return true;
}

int main () {
    
    int k = 10;

    cout << "All primes smaller than 1000:\n";
    for(int i=1; i<10000; i++) {
        if(isPrime(i, k)) {
            cout << i << " ";
        }
    }
    cout << endl;



    return 0;
}
