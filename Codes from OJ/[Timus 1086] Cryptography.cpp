/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
#define SIZE 1000000
 
int prime_ara[SIZE];
int ara[SIZE];
 
void seive()
{
    ara[0] = 1;
    ara[1] = 1;
    for(int i=2; i<SIZE; i++) {
        if(ara[i]==0) {
            for(int j=2; i*j<SIZE; j++) {
                ara[i*j] = 1;
            }
        }
    }
}
 
void prime_gen()
{
    for(int i=0, j=1; i<SIZE; i++) {
        if(ara[i]==0) {
            prime_ara[j] = i;
            j++;
        }
    }
}
 
int main()
{
    int k, n, i, j;
    seive();
    prime_gen();
 
    /*for(int i=1; i<25; i++) {
        printf("i = %d, ara[i] = %d\n", i, ara[i]);
    }*/
 
    /*for(int i=1; i<=25; i++) {
        printf("%d\n", prime_ara[i]);
    }*/
 
    cin >> k;
    for(i=0; i<k; i++) {
        cin >> n;
        cout << prime_ara[n] << endl;
    }
 
    return 0;
}
