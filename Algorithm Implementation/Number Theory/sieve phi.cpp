#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000006

int phi[SIZE], mark[SIZE];

void sievephi(int n) {
    //initialization
    for(int i=0; i<=n; i++) phi[i] = i;

    phi[1] = 1;
    mark[1] = 1;

    for(int i=2; i<=n; i++) {
        if(!mark[i])  { // if i is prime
            for(int j=i; j<=n; j+=i) {
                mark[j] = 1;
                //phi[j] will be divisible by i
                // so no need to worry.
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main() {
    sievephi(1000000);
    for(int i=0; i<=100; i++) {
        printf("phi[%d] = %d\n", i, phi[i]);
    }

    for(int i=0; i<=100; i++) {
        printf("mark[%d] = %d\n", i, mark[i]);
    }
    return 0;

}
