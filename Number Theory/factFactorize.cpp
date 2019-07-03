///use bitwise sieve if n>1e6
//vector is preferable
vector<int> Prime;
//int Prime[300000], nPrime;
//1 if not prime, 0 if prime
int mark[1000005];

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

///modify if needed
map<int, int> factFactorize (int n) {
    map<int, int> retMap;

    for (int i = 0; i < Prime.size() && Prime[i] <= n; i++) {
        int x = n;
        int freq = 0;

        while(x / Prime[i]) {
            freq += x / Prime[i];
            x = x / Prime[i];
        }

        retMap[Prime[i]] = freq;
    }

    return retMap;
}
