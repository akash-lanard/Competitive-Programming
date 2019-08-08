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

//number of prime factors in n factorial
//modify if needed
int ans[SIZE];

void preCalc() {
    sieve(1000000);

    ans[1] = 0;
    for (int i=2; i<=1000000; i++) {
        ans[i] = ans[i-1];

        int curr=i, j=0;
        while (mark[curr]) {
            if (curr%Prime[j]==0) {
                ans[i]++;
                curr /= Prime[j];
            }
            else j++;
        }
        if (!mark[curr]) ans[i]++;
    }
}
