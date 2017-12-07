#include <bits/stdc++.h>
using namespace std;

//vector is preferable
vector<int> Prime;
//int Prime[300000], nPrime;
//1 if not prime, 0 if prime
int mark[1000002];

void sieve(int n)
{
    int i, j, limit = sqrt(n*1.0) + 2;
    //1 is not prime
    mark[1] = 1;
    //evens
    for(i=4; i<=n; i+=2) mark[i] = 1;

    //2 is prime
    Prime.push_back(2);
    //run loops only on odds
    for(i=3; i<=n; i+=2) {
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
//n should be small
map<int, int> primeFactNFact(int n)
{
    map<int, int> m;
    for(int i=0; i<Prime.size(); i++) {
        if(Prime[i]>n) break;
        int temp2 = n;
        int cnt2=0;

        while(temp2>0) {
            cnt2 += (temp2/Prime[i]);
            temp2 /= Prime[i];
        }
        m[Prime[i]] = cnt2;
    }
    return m;
}

int main()
{
    sieve(1000000);
    int n;
    scanf("%d", &n);

    map<int, int> m;
    m = primeFactNFact(n);
    map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}

