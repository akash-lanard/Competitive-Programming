#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000002

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

//if d is large, it may require long long
map<int, int> primeFact(int d)
{
    map<int, int> m;
    int sq = sqrt(d);
    int temp = d;
    for(int i=0; i<Prime.size(); i++) {
        if(Prime[i]>sq) break;
        if(temp%Prime[i]==0) {
            int cnt=0;
            while(temp%Prime[i]==0) {
                temp /= Prime[i];
                cnt++;
            }
            m[Prime[i]] = cnt;
        }
    }
    if(temp>1) m[temp] = 1;
    return m;
}

int main()
{
    sieve(1000000);
    int d;
    scanf("%d", &d);

    map<int, int> m;
    m = primeFact(d);
    map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
