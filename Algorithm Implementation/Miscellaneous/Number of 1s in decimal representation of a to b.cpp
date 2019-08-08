#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL O[35]; // Number of 1's in binary representation of 0 to 2^n-1
          // 2^(n-1) + 2*O(n-1);
LL V[35]; // 2^n-1

void pre() {
    V[0] = 0;
    O[0] = 0;
    V[1] = 1;
    O[1] = 1;

    LL two = 1;
    for(int i=2; i<=32; i++) {
        two *= 2;
        O[i] = two + 2*O[i-1];
        V[i] = two*2 - 1;
    }
}

LL numOf1s(LL N) { // Number of 1's in binary representation of 0 to N
    LL temp = N;
    LL ret = 0;

    while(temp>0) {
        int i = 0;
        for(i=1; i<=32; i++) {
            if(V[i]>temp) break;
        }

        ret += O[i-1];

        LL diff = temp - V[i-1];

        ret += diff;

        temp = diff-1;
    }

    return ret;
}

int main () {
    pre();

    LL a, b;
    cin >> a >> b;

    cout << numOf1s(b) - numOf1s(a-1) << endl;

    return 0;
}


