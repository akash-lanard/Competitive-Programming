#include <bits/stdc++.h>
using namespace std;

#define LL long long

#define SIZE 10000002

vector<LL> Prime; //Prime vector
vector<LL> P; //Primes till sqrt(n)

int mark[SIZE]; //1 if not prime, 0 if prime

void sieve(LL n) {
    LL i, j, limit = sqrt(n*1.0) + 2;

    mark[1] = 1; //1 is not prime

    for(i=4; i<=n; i+=2) mark[i] = 1; //evens

    P.push_back(2); //2 is prime

    for(i=3; i<=n; i+=2) { //run loops only on odds
        if(!mark[i]) {
            P.push_back(i);

            //if we don't do it, following
            //i*i may overflow
            if(i<=limit) {
                for(j=i*i; j<=n; j += i*2) {
                    mark[j] = 1;
                }
            }
        }
    }
}

void segmentedSieve(LL low, LL high) {
    LL limit = sqrt(high) + 1; // segment size

    sieve(limit); // get primes till limit

    if(low==1) low++; // handle for 1

    memset(mark, false, sizeof(mark));

    for(LL i=0; i<P.size(); i++) {
        LL toLim = P[i] * P[i]; // all the composites before P[i]*P[i] are already marked

        if(toLim<low) toLim = ((low+P[i]-1)/P[i])*P[i]; // ceil(low/P[i])*P[i]

        for(LL j=toLim; j<=high; j+=P[i]) {
            mark[j-low] = 1;
        }
    }

    for(LL i=low; i<=high; i++) { // get primes for this segment
        if(!mark[i-low]) Prime.push_back(i);
    }
}

int main() {
    segmentedSieve(1000000000000, 1000001000000);

//    for(int i=0; i<P.size(); i++) {
//        printf("i = %d, P[i] = %lld\n", i, P[i]);
//    }
//
//    printf("\n\n");

    for(int i=0; i<20; i++) {
        printf("i = %d, Prime[i] = %lld\n", i, Prime[i]);
    }

    return 0;
}

