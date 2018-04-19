#include <bits/stdc++.h>
using namespace std;

///............................GCD.......................................

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}

///........................................................................

///............................Sieve.......................................

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

int main()
{
    sieve(100);

    for(int i=0; i<100; i++) {
        printf("%d %d\n", i, mark[i]);
    }

    cout << endl << endl;

    for(int i=0; i<25; i++) {
        printf("%d %d\n", i+1, Prime[i]);
    }
    return 0;
}

///........................................................................

///............................Bitwise Sieve.......................................

#define mx 100000000

int status[(mx/32)+2];
vector<int> Prime;

bool Check(int N, int pos){return (bool)(N & (1<<pos));}
int Set(int N, int pos) {return N = N|(1<<pos);}

void sieve(int N)
{
    int i, j, sqrtN(N);
    sqrtN = (int)sqrt(N);
    for(i=3; i<=sqrtN; i+=2) {
        if(Check(status[i>>5], i&31)==0) {
            for(j = i*i; j<=N; j += (i<<1)) {
                status[j>>5] = Set(status[j>>5], j&31);
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

int main()
{
    sieve(100000000);

    return 0;
}

///......................................................................

///............................Sieve Phi.......................................

int phi[1000006], mark[1000006];

void sievephi(int n)
{
    int i, j;

    //initialization
    for(i=0; i<=n; i++) phi[i] = i;

    phi[1] = 1;
    mark[1] = 1;

    for(int i=2; i<=n; i++) {
        if(!mark[i])  { // if i is prime
            for(j=i; j<=n; j+=i) {
                mark[j] = 1;
                //phi[j] will be divisible by i
                // so no need to worry.
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main()
{
    sievephi(1000000);
    for(int i=0; i<=100; i++) {
        printf("phi[%d] = %d\n", i, phi[i]);
    }

    for(int i=0; i<=100; i++) {
        printf("mark[%d] = %d\n", i, mark[i]);
    }
    return 0;

}

///......................................................................

///............................Loop Phi.......................................

int phi(int n)
{
    int ret = n;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            //i is a prime dividing n
            while(n%i==0) {
                //divide all factors of i
                n /= i;
            }
            //same as: ret * (1 - 1/p)
            ret -= ret/i;
        }
    }
    if(n>1) {
        //there can be only one prime greater
        //that sqrt(n) that divides n
        ret -= ret/n;
    }
    return ret;
}

int main()
{
    int n;
    while(1) {
        cin >> n;
        if(n==0) break;
        cout << phi(n) << endl;
    }
    return 0;
}

///......................................................................

///............................Bigmod.......................................


int bigmod(int a, int b, int M) //may require long long
{                               //check input range
    if(b==0) return 1%M;
    int x = bigmod(a, b/2, M);
    x = (x*x)%M;    //may overflow
    if(b%2==1) x = (x*a)%M;
    return x;
}

int main()
{
    int a, b, M;
    while(1) {
        cin >> a >> b >> M;
        if(a==0 && b==0 && M==0) break;
        cout << bigmod(a, b, M) << endl;
    }
    return 0;
}

///......................................................................

///............................ModString.......................................


int modString(string num, int m)
{
    int res = 0;
    for(int i=0; i<num.size(); i++) {
        res = (res*10 + (int)num[i] - '0') % m;
    }
    return res;
}

int main()
{
    while(1) {
        string str;
        cin >> str;
        if(str=="0") break;
        int ans = modString(str, 17);
        cout << ans << endl;
    }
    return 0;
}

///......................................................................

///............................NumOfDiv in O(sqrt(n)).....................


int numOfDiv(int n)
{
    int cnt = 0, sq = sqrt(n);
    for(int i=1; i<=sq; i++) {
        if(n%i==0) {
            if(n/i == i) cnt++;
            else cnt+=2;
        }
    }
    return cnt;
}

///......................................................................

///..........................Prime Factorization of a number...............

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

///.......................................................................

///..........................Prime Factorization of n!....................

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

///......................................................................

///............................NumOfDiv in n!.....................


double cumsum[10000010];

void f()
{
    cumsum[0] = 0.0;
    double sum = 0.0;
    for(int i=1; i<10000010; i++) {
        sum += log(i);
        cumsum[i] = sum;
    }
}

int main()
{
    f();
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        int n;
        scanf("%d", &n);
        int ans = cumsum[n]/log(10) + 1;
        printf("%d\n", ans);
    }
    return 0;
}

///......................................................................

///............................Leading digits of n (or n! or n^r).....................

//if we need leading digits of n! or n^r
//we can do it in the same method
//or even with different base
int leadDig(int n, int k)
{
    double x = (log(n)/log(10));
    double y = x - (int)x;
    long long res;
    if(y==0.0) res = pow(10, k-1);
    else res = pow(10, y) * pow(10, k-1);
    return res;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    cout << leadDig(n, k) << endl;

    return 0;
}

///......................................................................
///..................END OF TEMPLATE.....................................

