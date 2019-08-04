#include <bits/stdc++.h>
using namespace std;

#define LL long long

#define SIZE 1000002

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

void segmentedSieve(LL n) {
    LL limit = sqrt(n) + 1; // segment size

    sieve(limit); // get primes till limit

    LL low = 1; // current segment
    LL high = limit;

    while(low<n) {
        if(high>n) high = n;

        memset(mark, 0, sizeof(mark));

        for(LL i=0; i<P.size(); i++) {
            LL toLim = P[i] * P[i]; // all the composites before P[i]*P[i] are already marked

            if(toLim<low) toLim = ((low+P[i]-1)/P[i])*P[i]; // ceil(low/P[i])*P[i]

            for(LL j=toLim; j<=high; j+=P[i]) {
                mark[j-low] = 1;
            }
        }

        for(LL i=low; i<=high; i++) { // get primes for this segment
            if(!mark[i-low] && i!=1) Prime.push_back(i); // handle case for i = 1
        }

        low += limit;   // calculate for next segment
        high += limit;
    }
}

int main() {

    segmentedSieve(1000);

    for(int i=0; i<Prime.size(); i++) {
        printf("i = %d, Prime[i] = %d\n", i, Prime[i]);
    }

    return 0;
}
