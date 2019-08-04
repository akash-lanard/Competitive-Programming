#include <bits/stdc++.h>
using namespace std;

#define Set(N,p) N=((N)|((1LL)<<(p)))
#define Reset(N,p) N=((N)&(~((1LL)<<(p))))
#define Check(N,p) (!(((N)&((1LL)<<(p)))==(0)))

#define SIZE 100000000

int status[(SIZE/32)+2];
vector<int> Prime;


void sieve(int N) {
    int i, j, sqrtN(N);
    sqrtN = (int)sqrt(N);
    for(i=3; i<=sqrtN; i+=2) {
        if(!Check(status[i>>5], i&31)) {
            for(j = i*i; j<=N; j += (i<<1)) {
                Set(status[j>>5], j&31);
            }
        }
    }

    Prime.push_back(2);
    for(i=3; i<=N; i+=2) {
        if(Check(status[i>>5], i&31)==0) {
            Prime.push_back(i);
        }
    }
}

int main() {

    sieve(100000000);

    cout << "Prime contains (first 25):\n";
    for(int i=0; i<25; i++) {
        cout << Prime[i] << endl;
    }

    return 0;
}
