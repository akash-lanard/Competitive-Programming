#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000005

vector<int> Prime; //Prime vector

int mark[SIZE]; //1 if not prime, 0 if prime

void sieve(int n) {
    int i, j, limit = sqrt(n*1.0) + 2;

    mark[1] = 1; //1 is not prime

    for(i=4; i<=n; i+=2) mark[i] = 1; //evens

    Prime.push_back(2); //2 is prime

    for(i=3; i<=n; i+=2) { //run loops only on odds
        if(!mark[i]) {
            Prime.push_back(i);

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

int main() {

    sieve(100);

    for(int i=0; i<100; i++) {
        printf("i = %d, mark[i] = %d\n", i, mark[i]);
    }

    printf("\n\n");

    for(int i=0; i<25; i++) {
        printf("i = %d, Prime[i] = %d\n", i, Prime[i]);
    }
    return 0;
}
