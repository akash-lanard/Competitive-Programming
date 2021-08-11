///....................BASE TEMPLATE.........................
///====================== TEMPLATE STARTS HERE =====================///
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define POPCOUNT __builtin_popcountll
#define Set(N,p) ((N)|((1LL)<<(p)))
#define Reset(N,p) ((N)&(~((1LL)<<(p))))
#define Check(N,p) (!(((N)&((1LL)<<(p)))==(0)))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

#define LL long long
#define LLU long long unsigned int
typedef pair < int, int > pii;
typedef pair < LL, LL > pll;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<pll> vll;

#ifdef s_da_sailor
    #define line                    cout << "\n===================\n"
    #define trace(...)              __f( #__VA_ARGS__ , __VA_ARGS__ )
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << "\n";
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " = " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define line
    #define trace(...)
#endif // s_da_sailor

inline LL gcd ( LL a, LL b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

LL ext_gcd ( LL A, LL B, LL *X, LL *Y ){
    LL x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline LL modInv ( LL a, LL m ) {
    LL x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

inline LL bigmod ( LL a, LL p, LL m ) {
    LL res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1; /// For bigmod2 multiply here using mulmod
    }
    return res;
}


//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//int dir8[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
const LL inf = 2147383647;
const LL mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-11;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// For generating random numbers

///======================  TEMPLATE ENDS HERE  =====================///

void solve() {

}

int main () {
    #ifdef s_da_sailor
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // s_da_sailor

    fast_cin;

    solve();

    return 0;
}

///........................SIEVE.............................
#define SIZE 1000005
vector<int> Prime; ///Prime vector
int mark[SIZE]; ///1 if not prime, 0 if prime
void sieve(int n) {
    int i, j, limit = sqrt(n*1.0) + 2;
    mark[1] = 1; ///1 is not prime
    for(i=4; i<=n; i+=2) mark[i] = 1; ///evens
    Prime.push_back(2); ///2 is prime
    for(i=3; i<=n; i+=2) { ///run loops only on odds
        if(!mark[i]) {
            Prime.push_back(i);
            if(i<=limit) {///if we don't do it, following
                for(j=i*i; j<=n; j += i*2) {///i*i may overflow
                    mark[j] = 1;
                }
            }
        }
    }
}
///.....................BITWISE SIEVE.........................
#define SIZE 100000005 /// Check, Set, Reset must be defined
int status[(SIZE/32)+2]; /// bit is 0 = prime, 1 = non-prime
vector<int> Prime;  /// Prime vector
void sieve(int N) {
    int i, j, sqrtN(N);
    sqrtN = (int)sqrt(N);
    for(i=3; i<=sqrtN; i+=2) {
        if(!Check(status[i>>5], i&31)) { /// i>>5 = i/32, i&31 = i%32
            for(j = i*i; j<=N; j += (i<<1)) {
                Set(status[j>>5], j&31);
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
///...................SEGMENTED SIEVE..............................
#define SIZE 10000005
vector<LL> Prime; ///Prime vector
vector<LL> P; ///Primes till sqrt(n) (For sieve)
void segmentedSieve(LL low, LL high) { /// Sieve must be included
    LL limit = sqrt(high) + 1; /// segment size
    sieve(limit); /// get primes till limit
    if(low==1) low++; /// handle for 1
    memset(mark, false, sizeof(mark));
    for(LL i=0; i<P.size(); i++) {
        LL toLim = P[i] * P[i]; /// all the composites before P[i]*P[i] are already marked
        if(toLim<low) toLim = ((low+P[i]-1)/P[i])*P[i]; /// ceil(low/P[i])*P[i]
        for(LL j=toLim; j<=high; j+=P[i]) {
            mark[j-low] = 1;
        }
    }
    for(LL i=low; i<=high; i++) { /// get primes for this segment
        if(!mark[i-low]) Prime.push_back(i);
    }
}
///………..Sieve+Mobius/// O(NlogN).................
#define MAXP        100005
vector <int> prime;
int mob[MAXP];
bitset<MAXP> a;
void sieve(){
    int m; m=sqrt(MAXP);
    a[0]=true; a[1]=true;
    for(int i=0;i<MAXP;i++)mob[i]=1; //for mobius
    mob[2]=-1; //for mobius
    prime.push_back(2);
    for(int i=4;i<MAXP;i+=2){
        a[i]=true;
        mob[i]*=(i%4)? -1:0; //for mobius
    }
    for(int i=3;i<MAXP;i+=2){
        if(a[i]==0){
            prime.push_back(i);
            mob[i]=-1; //for mobius
            if(i<=m){ //don’t use this if condition for mobius
                for(int j=i*i;j<MAXP;j+=2*i){ 
                //for(int j=2*i;j<MAXM;j+=i) for mobius
                    a[j]=true;
                   //becareful this might need long long
                   mob[j]*=(j%(i*i))? -1:0; //for mobius
    	}
          }
       }
    }

///...................PrimeFactNFact..............................
map<int, int> primeFactNFact(int n) {///n should be small
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
///............................Sieve Phi.......................................
int phi[1000006], mark[1000006];
void sievephi(int n) {
    int i, j;
    for(i=0; i<=n; i++) phi[i] = i;///initialization
    phi[1] = 1;
    mark[1] = 1;
    for(int i=2; i<=n; i++) {
        if(!mark[i])  { /// if i is prime
            for(j=i; j<=n; j+=i) {
                mark[j] = 1;///phi[j] will be divisible by i
                phi[j] = phi[j]/i*(i-1);/// so no need to worry.
            }
        }
    }
}
///............................Loop Phi.......................................
int phi(int n) {
    int ret = n;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {///i is a prime dividing n
            while(n%i==0) {///divide all factors of i
                n /= i;
            }
            ret -= ret/i;///same as: ret * (1 - 1/p)
        }
    }
    if(n>1) {///there can be only one prime greater
        ret -= ret/n;///that sqrt(n) that divides n
    }
    return ret;
}
///...................MULMOD.................................
LL mulmod(LL a, LL b, LL mod) {
    LL res = 0; /// Initialize result
    a = a % mod;
    while (b > 0) { /// If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
        a = (a * 2) % mod; /// Multiply 'a' with 2
        b /= 2; /// Divide b by 2
    }
    return res % mod; /// Return result
}
///............................NumOfDig in n!.....................
double cumsum[10000010];
void f() {///return ans = cumsum[n]/log(base) + 1;
    cumsum[0] = 0.0;
    double sum = 0.0;
    for(int i=1; i<10000010; i++) {
        sum += log(i);
        cumsum[i] = sum;
    }
}
///.......................Leading digits of n (or n! or n^r)...................
///if we need leading digits of n! or n^r
///we can do it in the same method
///or even with different base
int leadDig(int n, int k) {
    double x = (log(n)/log(10)); /// change base
    double y = x - (int)x;
    long long res;
    if(y==0.0) res = pow(10, k-1);  /// may use pow manually
    else res = pow(10, y) * pow(10, k-1);
    return res;
}
///………...First K digit of n!,n^r///(LogN)................
//first K digits of N^P, N!
long double arr[MAXN];
void precal(){
    for(long long int i=1;i<MAXN;i++){
        arr[i]=arr[i-1]+log10(i*1.0);
    }
}
long long int findfirst(long long int n, long long int p, long long int k){
    long double m;
    m=p*(log10(1.0*n)); //forN^P
    //m=arr[n] forN!
    long long int x=(long long int)m;
    m=m-x;
    m=pow(10.0,m);
    long long int val=1;
    for(int i=1;i<k;i++)val*=10;
    while(m<val&&m){
        m=m*10;
    }
    return (long long int)(m);
}
///.............CRT non coprime mod online.......................
/// #define __int128 LL /// Change here if __int128 is not supported
/**
    A CRT solver which works even when moduli are not pairwise coprime
    1. Call clear()
    2. Add equations using addEquation() method
    3. Call solve() to get {x, N} pair, where x is the unique solution modulo N.
    Assumptions: LCM of all mods will fit into long long.
*/
class ChineseRemainderTheorem {
    typedef long long vlong;
    typedef pair<vlong,vlong> pll;

    /** CRT Equations stored as pairs of vector. See addEqation()*/
    vector<pll> equations;
public:
    void clear() {
        equations.clear();
    }
    /** Add equation of the form x = r (mod m)*/
    void addEquation( vlong r, vlong m ) {
        equations.push_back({r, m});
    }
    pll solve() {
        if (equations.size() == 0) return {-1,-1}; /// No equations to solve
        vlong a1 = equations[0].first;
        vlong m1 = equations[0].second;
        a1 %= m1;
        /** Initially x = a_0 (mod m_0)*/
        /** Merge the solution with remaining equations */
        for ( int i = 1; i < equations.size(); i++ ) {
            vlong a2 = equations[i].first;
            vlong m2 = equations[i].second;
            vlong g = __gcd(m1, m2);
            if ( a1 % g != a2 % g ) return {-1,-1}; /// Conflict in equations
            /** Merge the two equations*/
            vlong p, q;
            ext_gcd(m1/g, m2/g, &p, &q);
            vlong mod = m1 / g * m2;
            vlong x = ( (__int128)a1 * (m2/g) % mod *q % mod + (__int128)a2 * (m1/g) % mod * p % mod ) % mod;
            /** Merged equation*/
            a1 = x;
            if ( a1 < 0 ) a1 += mod;
            m1 = mod;
        }
        return {a1, m1};
    }
};
///......................CRT pairwise coprime mod online............
/// Doesn't work when the mod values aren't pairwise co-prime
vector<LL> A, M; /// A = list of remainders, M = list of mod values
LL CRT(vector<LL> &A, vector<LL> &M){
    LL a1 = A[0], m1 = M[0];        /// may require 128 bit int here (__int128u_t)
    for(int i=1; i<A.size(); i++){
        LL a2 = A[i], m2 = M[i];
        LL p, q;
        ext_gcd(m1, m2, &p, &q);
        LL mod = m1*m2;
        LL x = ((((a1*m2)%mod)*q)%mod + (((a2*m1)%mod)*p)%mod)%mod;
        a1 = x;
        m1 = mod;
        if(a1<0) a1 += mod;
    }
    if(a1<0) a1 += m1;
    return a1;
}
///...................Linear Diophantine Equation.................
///if res == false  No Solution
///One Possible Solution x, y
///Another Possible Solutions x + k * ( B / g ), y - k * ( A / g )
bool linearDiophantine(LL A, LL B, LL C, LL *X, LL *Y) {
    LL g = gcd(A, B);
    if(C%g!=0) return false;     /// no solution
    LL a = A/g, b = B/g, c = C/g;
    ext_gcd(a, b, X, Y);        /// solve aX + bY = 1
    if(g<0) {                   /// make sure gcd(a, b) = 1
        a *= ((LL)(-1)); b *= ((LL)(-1)); c *= ((LL)(-1));
    }
    *X *= c; *Y *= c;           /// aX + bY = c
    return true;
}
///.....................NT NOTES..............................
**Amount of prime numbers non greater than n is about n/log(n).
Amount of palindrome numbers with fixed length k — it is about 10^((k+1)/2).
Therefore the number of primes asymptotically bigger than the number of palindromic numbers.

**F(n)=4*F(n-3)+F(n-6)  where, F(n) = nth fibonacci number

**All primes greater than 3 can be written in the form 6k+1 or 6k-1.
**Any number n can have only one primefactor greater than sqrt(n)

**For every Pythagorean triplet a > 3 and a + b + c is even

**A Pythagorean triplet (a, b, c) is by definition primitive if a, b, c are pairwise co-prime
**All primitive Pythagorean triplets can be represented as a = (m^2) − (n^2), b = 2*m*n, c = (m^2) + (n^2)
with m > n > 0, perhaps exchanging a and b to have a < b. These formulae
always produce a Pythagorean triplet, but it will be primitive if and only if
exactly one of m, n is even and other is odd and gcd(m, n) = 1
**From any Pythagorean triplet you get a primitive one by dividing out the greatest
common divisor, so every Pythagorean triplet has a unique representation a = ((m^2) − (n^2))*d, b = 2*m*n*d, c = ((m^2) + (n^2))*d
with m > n > 0, gcd(m, n) = 1 and exactly one of m, n even and d is the gcd of a, b and c

**D(t) = D(n/2)(D(n+1) if n is even
or D(t) = D(n)(D((n+1)/2) if (n+1) is even
D(t) = number of divisors of a triangular number
///.........................DSU..................................................
#define SIZE 150005 ///change SIZE
int parent[SIZE];
int sz[SIZE];
void makeset(int u) {
    parent[u] = u;
    sz[u] = 1;
}
void init_disjoint_set(int N) {
    for(int i=0; i<N; i++) {
        makeset(i);
    }
}
int FindRepresentative(int r) {  ///with path compression
    if(parent[r]==r) {
        return r;
    }
    parent[r] = FindRepresentative(parent[r]);
    return parent[r];
}
int FindSize(int r) {
    return sz[FindRepresentative(r)];
}
void Union(int a, int b) {
    int u = FindRepresentative(a);
    int v = FindRepresentative(b);
    if(u!=v) {
        if(sz[v]>=sz[u]) {
            parent[u] = v;
            sz[v] += sz[u];
        }
        else {
           parent[v] = u;
            sz[u] += sz[v];
        }
    }
}	     
/// PURQ Struct Sum Query, Point Update & Range Query
#define SIZE 100005
int N, Q;
struct SegmentTree {
    int arr[SIZE], Tree[4*SIZE];
    inline void Init() {
        memset(Tree, 0, sizeof(Tree));
    }
    inline void Build(int node = 1, int b = 1, int e = N) {
        if(b > e) return;
        if(b == e) { Tree[node] = arr[b]; return; }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        Build(left, b, mid);
        Build(right, mid+1, e);
        Tree[node] = Tree[left] + Tree[right];              /// change here
    }
    inline void Update(int pos, int val, int node = 1, int b = 1, int e = N) {
        if(pos > e || pos < b || b > e) return;
        if(b == e && b == pos) { Tree[node] = arr[b] = val; return; }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        Update(pos, val, left, b, mid);
        Update(pos, val, right, mid+1, e);
        Tree[node] = Tree[left] + Tree[right];              /// change here
    }
    inline int Query(int i, int j, int node = 1, int b = 1, int e = N) {
        if(i > e || j < b || b > e) return 0;               /// change here
        if(i <= b && j >= e) return Tree[node];
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        int Q1 = Query(i, j, left, b, mid);
        int Q2 = Query(i, j, right, mid+1, e);
        return (Q1 + Q2);                                   /// change here
    }
} ST;	      
/// PURQ Struct (Merge Sort Tree)
#define SIZE 30005
int N, Q;
struct SegmentTree {
    int arr[SIZE];
    vector<int> Tree[4*SIZE];
    inline void Init() {
        for(int i=0; i<4*SIZE; i++) Tree[i].clear();
    }
    inline void Build(int node = 1, int b = 1, int e = N) {
        if(b > e) return;
        if(b == e) { Tree[node].push_back(arr[b]); return; }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        Build(left, b, mid);
        Build(right, mid+1, e);
        merge(Tree[left].begin(), Tree[left].end(), Tree[right].begin(), Tree[right].end(), back_inserter(Tree[node]));
    }
    inline int Query(int i, int j, int val, int node = 1, int b = 1, int e = N) { /// Number of elements greater than val
        if(i > e || j < b || b > e) return 0;
        if(i <= b && j >= e) return (e-b+1) - (upper_bound(Tree[node].begin(), Tree[node].end(), val) - Tree[node].begin()); /// Change here
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        int Q1 = Query(i, j, val, left, b, mid);
        int Q2 = Query(i, j, val, right, mid+1, e);
        return (Q1 + Q2);     /// Change here
    }
} ST;	       
/// RURQ Struct  Sum Query, Range add value Update & Range sum Query
#define SIZE 100005
int N, Q;
struct SEGMENT_TREE {
    int arr[SIZE], Tree[4*SIZE], Lazy[4*SIZE];
    inline void Init() {
        memset(Tree, 0, sizeof(Tree));
        memset(Lazy, 0, sizeof(Lazy));
    }
    inline void LazyPropagate(int node, int b, int e) {
        if(Lazy[node] != 0) {
            Tree[node] += (Lazy[node] * (e-b+1));       /// change here
            if(b != e) {
                Lazy[2*node] += Lazy[node];             /// change here
                Lazy[2*node + 1] += Lazy[node];         /// change here
            }
            Lazy[node] = 0;
        }
    }
    inline void Build(int node = 1, int b = 1, int e = N) {
        if(b > e) return;
        if(b == e) { Tree[node] = arr[b]; return; }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        Build(left, b, mid);
        Build(right, mid+1, e);
        Tree[node] = Tree[left] + Tree[right];          /// change here
    }
    inline void Update(int i, int j, int val, int node = 1, int b = 1, int e = N) {
        LazyPropagate(node, b, e);
        if(i > e || j < b || b > e) return;
        if(i <= b && j >= e) {
            Lazy[node] = val;
            LazyPropagate(node, b, e);
            return;
        }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        Update(i, j, val, left, b, mid);
        Update(i, j, val, right, mid + 1, e);
        Tree[node] = Tree[left] + Tree[right];          /// change here
    }
    inline int Query(int i, int j, int node = 1, int b = 1, int e = N) {
        LazyPropagate(node, b, e);
        if(i > e || j < b || b > e) return 0;           /// change here
        if(i <= b && j >= e) return Tree[node];
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        int Q1 = Query(i, j, left, b, mid);
        int Q2 = Query(i, j, right, mid+1, e);
        return (Q1 + Q2);                               /// change here
    }
} ST;  
/// RURQ Struct (Set1 Set0 Flip)        
#define SIZE 1025000
int N, Q;
struct SEGMENT_TREE {
    int arr[SIZE], Tree[4*SIZE], Lazy[4*SIZE];
    inline void Init() {
        memset(arr, 0, sizeof(arr));
        memset(Tree, 0, sizeof(Tree));
        memset(Lazy, -1, sizeof(Lazy));
    }
    inline void LazyPropagate(int node, int b, int e) {
        if(Lazy[node] != -1) {
            if(Lazy[node] == 1) Tree[node] = (e-b+1);
            else if(Lazy[node] == 0) Tree[node] = 0;
            else Tree[node] = (e-b+1) - Tree[node];
            if(b != e) {
                if(Lazy[node] != 2) {
                    Lazy[2*node] = Lazy[node];
                    Lazy[2*node + 1] = Lazy[node];
                }
                else {
                    if(Lazy[2*node]==0) Lazy[2*node] = 1;
                    else if(Lazy[2*node]==1) Lazy[2*node] = 0;
                    else if(Lazy[2*node]==2) Lazy[2*node] = -1;
                    else Lazy[2*node] = 2;
                    if(Lazy[2*node + 1]==0) Lazy[2*node + 1] = 1;
                    else if(Lazy[2*node + 1]==1) Lazy[2*node + 1] = 0;
                    else if(Lazy[2*node + 1]==2) Lazy[2*node + 1] = -1;
                    else Lazy[2*node + 1] = 2;
                }
            }
            Lazy[node] = -1;
        }
    }
    inline void Build(int node = 1, int b = 0, int e = N-1) {
        if(b > e) return;
        if(b == e) { Tree[node] = arr[b]; return; }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        Build(left, b, mid);
        Build(right, mid+1, e);
        Tree[node] = Tree[left] + Tree[right];
    }
    inline void Update(int i, int j, int val, int node = 1, int b = 0, int e = N-1) {
        LazyPropagate(node, b, e);
        if(i > e || j < b || b > e) return;
        if(i <= b && j >= e) {
            Lazy[node] = val;
            LazyPropagate(node, b, e);
            return;
        }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        Update(i, j, val, left, b, mid);
        Update(i, j, val, right, mid + 1, e);
        Tree[node] = Tree[left] + Tree[right];
    }
    inline int Query(int i, int j, int node = 1, int b = 0, int e = N-1) {
        LazyPropagate(node, b, e);
        if(i > e || j < b || b > e) return 0;
        if(i <= b && j >= e) {
            return Tree[node];
        }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        int Q1 = Query(i, j, left, b, mid);
        int Q2 = Query(i, j, right, mid+1, e);
        return (Q1 + Q2);
    }
} ST;       
///...........................Trie Array.........................
#define SIZE 100000
/// Trie Array Based Implementation
/// Call insert() to insert new string
/// Call search() to search a string
struct node {
    int cnt; int child[55]; /// Change here if you need
};
node T[SIZE];
struct Trie {
    int id;
    void createNode() {
        T[id].cnt = 0;
        memset(T[id].child, -1, sizeof(T[id].child));
        id++;
    }
    void clear() {
        id = 0; createNode();
    }
    /// Returns the corresponding integer id of the character
    int FID(const char &c) {
        if(c>='A' && c<='Z') return c - 'A';
        else return (c - 'a') + 26;
    }
    void insert(string &s) {
        int cur = 0;
        T[cur].cnt++;
        for(int i=0; i<s.size(); i++) {
            int p = FID(s[i]);
            if(T[cur].child[p]==-1) {
                T[cur].child[p] = id;
                createNode();
            }
            cur = T[cur].child[p];
            T[cur].cnt++;
        }
    }
    /// Returns number of occurance of s.
    int search(string &s) {
        int cur = 0;
        for(int i=0; i<s.size(); i++) {
            int p = FID(s[i]);
            if(T[cur].child[p]==-1) return 0;
            cur = T[cur].child[p];
        }
        return T[cur].cnt;
    }
}root;
///.............Trie Recursive...................
/// Trie Recursion based implementation
/// Create the root (root = new Trie())
/// Use insert and search accordingly
/// At the end call delete_trie() to delete all the nodes
/// Done for only digits by default
#define SIZE 10
class Trie {
    bool ed; Trie *child[SIZE];
    /// If ed is true, a word is finished here
public:
    Trie() {
        ed = false;
        for(int i=0; i<SIZE; i++) {
            child[i] = NULL;
        }
    }
    /// Delete to save memory
    void delete_trie() {
        for(int i=0; i<SIZE; i++) {
            if(child[i]!=NULL) {
                child[i]->delete_trie();
                delete child[i];
            }
        }
    }
    void insert(string &word, int pos) {
        if(pos==(int)word.length()) {
            ed = true;
            return;
        }
        int c = (int)(word[pos] - '0'); ///change here
        if(child[c] == NULL) {
            child[c] = new Trie();
        }
        return child[c]->insert(word, ++pos);
    }
    bool search(string &word, int pos) {
        if(pos==(int)word.length()) return ed;
        int c = (int)(word[pos] - '0');
        if(child[c]==NULL) return false;
        return child[c]->search(word, ++pos);
    }
}*root;

///......................MST(Kruskal's).......................
/// DSU needs to be defined
#define SIZE 3005
int parent[SIZE];
int flag, cnt, sum;
struct edge {
    int u, v, w;
    edge() { }
    edge(int a, int b, int c) {
        u = a; v = b; w = c;
    }
};
bool comp(const edge& a, const edge& b) {
    if(a.w < b.w) return true;
    else return false;
}
vector<edge> edgeVec;
double mst(int n) {
    sort(edgeVec.begin(), edgeVec.end(), comp);
    init_disjoint_set(SIZE);
    cnt = 0; sum = 0;
    for(int i=0; i<edgeVec.size(); i++) {
        flag = 0;
        Union(edgeVec[i].u, edgeVec[i].v);
        if(flag) {
            cnt++;
            sum += edgeVec[i].w;
            if(cnt==n-1) break;
        }
    }
    return sum;
}
void clr() {
    edgeVec.clear();
}
///.....................Topsort......................
#define SIZE 105
vector<int> G[SIZE], L;
queue<int> Q;
int inDegree[SIZE];/// Calculate while taking input
void topsort(int N) {
    L.clear();
    while(!Q.empty()) Q.pop();
    for(int i=1; i<=N; i++) {
        if(inDegree[i]==0) {
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        L.push_back(u);
        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v]==0) {
                Q.push(v);
            }
        }
    }
}
void clr() {
    for(int i=0; i<SIZE; i++) G[i].clear();
    memset(inDegree, 0, sizeof(inDegree));
}
///........................Bellman Ford........................
#define SIZE 1005
#define BIG 1000000000000005
long long dis[SIZE];
int pre[SIZE];
int n;
vector<pair<int, int> > G[SIZE];
bool bellmanFord(int source) {
    for(int i=0; i<SIZE; i++) {
        dis[i] = BIG; pre[i] = -1;
    }
    dis[source] = 0;
    for(int i=1; i<=n-1; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=0; k<G[j].size(); k++) {
                int currID = G[j][k].first;
                int currCost = G[j][k].second;
                if(dis[j] + currCost < dis[currID]) {
                    dis[currID] = dis[j] + currCost;
                    pre[currID] = j;
                }
            }
        }
    }
    for(int j=1; j<=n; j++) {
        for(int k=0; k<G[j].size(); k++) {
            int currID = G[j][k].first;
            int currCost = G[j][k].second;
            if(dis[j] + currCost < dis[currID]) {
                return false;
            }
        }
    }
    return true;
}
void clr() {
    for(int i=0; i<SIZE; i++) G[i].clear();
}
///..................Treap Builtin.......................
/// Importing policy_based_data_structure:
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/// Importing ends here.
struct vals{ /// struct for declaring struct type pb_ds:
    int num, typ;
    vals(int a, int b){
        num = a;
        typ = b;
    }
    bool operator <(const vals& other) const {
        return num > other.num;
    }
};
/// Supports all the operations of a set including two additional features:
/// 1. find_by_order(k) # Returns an iterator pointing to the k-th smallest element (zero based).
/// 2. order_of_key(k) # Returns the number of elements strictly smaller than k.
int main(){
    /// typedef original name to pb_ds for simplicity:
    typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;
    /// Ordered Set
    pb_ds treap;
    treap.insert(2); /// Insert an element
    treap.insert(3);
    cout << treap.order_of_key(5) << endl; /// Returns number of elements smaller than k
    pb_ds::iterator it = treap.find_by_order(0); /// Returns an iterator pointing to the k-th smallest element
    cout << *it << endl; /// Print the element
    /// Iterate though the elements (similar to a set)
    for(pb_ds::iterator it = treap.begin(); it != treap.end(); it++){
        cout << *it << endl;
    }
    treap.erase(2); /// Erase an element
    treap.clear(); /// Clear the treap
    /// Struct type pb_ds. Ordering depends on the operator overloading inside the struct.
    typedef tree <vals, null_type, less<vals>, rb_tree_tag, tree_order_statistics_node_update> pb_ds_st;
    /// Ordered Multiset. Notice the less_equal<int> parameter.
    typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
    ordered_multiset tmset;
    tmset.insert(2);
    tmset.insert(2);
    /// Erasing is very tricky in Ordered Multiset
    tmset.erase(tmset.find_by_order(tmset.order_of_key(2))); /// Erase 2 (Just one of the 2's get erased)
    /// Pair <int,int> type Ordered Set
    typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pair;
}
///........................LIS NlogN............................
#define Size 100005
#define Mod 1000000007LL
int N, A[100005], LIS[100005], LDS[100005];
vector<int> List;
void calculate_LIS(){
    List.clear();
    for(int i = 0;i<N;i++){
        vector<int>::iterator low = lower_bound(List.begin(),List.end(),A[i]);
        LIS[i] = (low - List.begin());
        if(low == List.end()) List.pb(A[i]);
        else *low = A[i];
    }
}
void calculate_LDS(){
    List.clear();
    reverse(A,A+N);
    for(int i = 0;i<N;i++){
        vector<int>::iterator low = lower_bound(List.begin(),List.end(),A[i]);
        LDS[i] = (low - List.begin());
        if(low == List.end()) List.pb(A[i]);
        else *low = A[i];
    }
    reverse(A,A+N);
    reverse(LDS,LDS+N);
}
void solve(){
    calculate_LIS();
    calculate_LDS();
    /// LIS[i] = length of LIS found till position i;
    /// LDS[i] = length of LDS found till position i;
    int resLIS = 0,resLDS = 0;
    for(int i = 0;i<N;i++){
        resLIS = max(resLIS,LIS[i]);
        resLDS = max(resLDS,LDS[i]);
    }
    pf("LIS: %d , LDS: %d\n",resLIS,resLDS);
}
///………..LIS min max path///(NlogN+N)..........
//reverse the array and calculate the LDS
//save the position in LDS for each element in LISpath array
//LISpath will have the index of the elements
void MINMAXLIS(){
    int lastind = MAXN , lasttaken = -1;
    for(int i=v.size();i>0;i--){
        int ind=-1,val=MAXN; ///val=-1 for MAX path
        for(int j=0;j<LISpath[i].size();j++){
            if(LISpath[i][j]<lastind&&arr[LISpath[i][j]]>lasttaken){
             //if(LISpath[i][j]<lastind&&arr[LISpath[i][j]]>=lasttaken) for duplicate value
    if(val>=arr[LISpath[i][j]]){  /// if(val<=arr[LISpath[i][j]]) MAX path
                    ind=LISpath[i][j];
                    val=arr[LISpath[i][j]];
                }
            }
        }
        lastind=ind;
        lasttaken=val;
        ans.push_back(val);
    }
    for(auto x: ans){
        cout<<x;
    }cout<<endl;
}
///............Binomial coeff......................
int DP[Size][Size];
void binomialCoeff() {
    CLR(DP,0);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                DP[i][j] = 1;
            } else {
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
            }
        }
    }
}
///...................Matrix Expo.....................
/**
    Recurrence: f(n+1) = f(n) + f(n-1)
    Given: f(0) = a, f(1) = b
    Matrix Equation: A * X = B
    A = |1 1| X = |f(0)| B = |f(0) + f(1)|
        |1 0|     |f(1)|     |     f1    |
    Find f(n+1) = B = A^n * X
    How To Use?
    1. Call buildMatrix() and store values accordingly
    2. Find B = bigMatMod(A, n - 1)
    3. Find B = multiply(B, X)
    4. Now, f(n) = B.m[0][0]
**/
#define MXR 5 /// Change here
#define MXC 5
struct matrix{
    int R, C;
    LL m[MXR][MXC];
    matrix(){}
    matrix(int r, int c){
        R = r; C = c;
    }
    void clear(int r, int c){
        R = r; C = c;
    }
};
matrix multiply(matrix a, matrix b){
    matrix res(a.R, b.C);
    for(int r1 = 0; r1<a.R; r1++){
        for(int c1 = 0; c1<a.C; c1++){
            res.m[r1][c1] = 0;
            for(int k = 0; k<a.C; k++){
                res.m[r1][c1] += (a.m[r1][k]*b.m[k][c1]); /// mod here if needed
            }
        }
    }
    return res;
}
matrix bigMatMod(matrix a, LL p){
    if(p == 1) return a;
    if(p%2 == 1) {
        return multiply(a, bigMatMod(a, p-1));
    } else {
        matrix res = bigMatMod(a, p/2);
        return multiply(res, res);
    }
}
matrix A, B, X;
LL a, b; /// f(0) = a, f(1) = b
void buildMatrix(){
    /// Set row column accordingly
    A.clear(2, 2); B.clear(2, 1);
    /// Store initial values in the matrix
    A.m[0][0] = 1; A.m[0][1] = 1; A.m[1][0] = 1; A.m[1][1] = 0;
    X.m[0][0] = b; X.m[1][0] = a;
}
///......................Mobius Function.............................
/// Mobius function is a function which has one of the following values:
/// mobius(x) = -1 : square free number with odd prime factors
/// mobius(x) = 1  : square free number with even prime factors
/// mobius(x) = 0  : not a square free number
/// Store all the prime till N in vector prime, then call mobiusCalc(N)
int mobius[Size+10];
void mobiusCalc(int n){
    FOR(i,1,n) mobius[i] = 1; ///Initially all value is 1
    ///Mark all numbers with square factors 0
    int sqrtn = sqrt(n)+1;
    FOR(i,0,SZ(prime)-1) {
        if(prime[i]>sqrtn) break;
        int x = SQ(prime[i]);
        for(int j = x; j <= n; j += x) mobius[j] = 0;
    }
    ///For each prime, all it's multiple gets multiplied by -1
    FOR(i,0,SZ(prime)-1){
        for(int j = prime[i]; j <= n; j += prime[i]) mobius[j] *= -1;
    }
}
/// Application of Mobius function:
/// It is mainly used with inclusion exclusion, when items are the first K primes.
/// Complexity is improved from 2^k to NloglogN
/// Ex1: Number of pair (x,y) whose gcd is 1
/// Ex2: Summation of gcd(x,y) for all pair of 1<=x,y<=N
///…………………… Maximum Matching ……………………
// Call clear()
// Both sides have nodes starting from 1
// Call findMatching() to get maximum matching
// If Left[u] != 0 then (u and Left[u]) make a matching
// Complexity (sqrt(V)*E)
const int SIZE = 40005; // Maximum no of node(1 based indexing)
int n, m, A[SIZE], B[SIZE];
int Left[SIZE], Right[SIZE], dist[SIZE];
vector<int> G[SIZE];
struct HOPCROFT{
    int nNode, matching;
    void clear(int N){
        for(int i=0; i<=N; i++) G[i].clear();
        matching = 0;
        memset(Left, 0, sizeof(Left));
        memset(Right, 0, sizeof(Right));
        memset(dist, 0, sizeof(dist));
        nNode = N;
    }
    void addEdge(int u, int v){
        G[u].pb(v);
    }
    bool BFS() {
        queue<int> Q;
        for(int i=1; i<=nNode; i++) {
            if(Left[i] == 0) {
                dist[i] = 0;
                Q.push(i);
            }
            else {
                dist[i] = inf;
            }
        }
        dist[0] = inf;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            if(u != 0) {
                int len = G[u].size();
                for(int i=0; i<len; i++) {
                    int v = G[u][i];
                    if(dist[Right[v]] == inf) {
                        dist[Right[v]] = dist[u] + 1;
                        Q.push(Right[v]);
                    }
                }
            }
        }
        return (dist[0] != inf);
    }
    bool DFS(int u) {
        if(u != 0) {
            int len = G[u].size();
            for(int i=0; i<len; i++) {
                int v = G[u][i];
                if(dist[Right[v]] == dist[u]+1) {
                    if(DFS(Right[v])) {
                        Right[v] = u;
                        Left[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = inf;
            return false;
        }
        return true;
    }
    int findMatching() {
        while(BFS()){
            for(int i=1; i<=nNode; i++){
                if(Left[i] == 0 && DFS(i)){
                    matching++;
                }
            }
        }
        return matching;
    }
}hopcroft;               
///……………………..Geo Formula…………………………
Cosine Rule: c2 = a2 + b2 − 2ab cos(C)
Sine Rule: a / sin A = b / sin B = c / sin C
///…………………....Geo Base………………………………
/// Geometry Base Template
/// Include necessary functions from here to use in other codes
/// If coordinates are double, change accordingly

struct Point {
    LL x, y;
    Point(){}
    Point(LL a, LL b){
        x = a, y = b;
    }
    Point operator - (const Point &t) const{
        Point res;
        res.x = x - t.x;
        res.y = y - t.y;
        return res;
    }
};
LL sqrDist(Point P, Point Q) {
    return (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
}
double dist(Point P, Point Q) {
    double res = (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
    return sqrt(res);
}
/// 0 = Collinear, 1 = Clockwise, 2 = Counterclockwise.
int orientation(Point P, Point Q, Point R) {
    LL ret = (Q.y - P.y) * (R.x - Q.x) - (Q.x - P.x) * (R.y - Q.y);
    if (ret > 0) return 1; /// Polar angle of (Q - R) is smaller than (P - Q) with respect to x axis.
    if (ret < 0) return 2; /// Polar angle of (Q - R) is greater than (P - Q) with respect to x axis.
    return 0; /// Co linear
}
double polygonArea(vector<Point> polygon) {
    double area = 0;
    for (int i = 1; i + 1 < polygon.size(); i++){
        area += (polygon[i].y - polygon[0].y) * (polygon[i + 1].x - polygon[i].x)
                - (polygon[i].x - polygon[0].x) * (polygon[i + 1].y - polygon[i].y);
    }
    return FABS(area / 2.0);
}
/// Compute A X B:
int crossAB(Point A, Point B){
    return (A.x * B.y - A.y * B.x);
}
/// Compute A dot B:
int dotAB(Point A, Point B){
    return (A.x * B.x + A.y * B.y);
}
/// Compute the cross product AB X AC
int crossABC(Point A, Point B, Point C) {
    Point AB = Point(B.x - A.x, B.y - A.y); /// AB vector
    Point AC = Point(C.x - A.x, C.y - A.y); /// AC vector
    return crossAB(AB, AC);
}
/// Compute the dot product AB dot BC
int dotABC(Point A, Point B, Point C) {
    Point AB = Point(B.x - A.x, B.y - A.y); /// AB vector
    Point BC = Point(C.x - B.x, C.y - B.y); /// BC vector
    return dotAB(AB, BC);
}
/// The angle between two vectors:
double angle(Point A, Point B){
    double ans = fabs((atan2(A.y, A.x) - atan2(B.y, B.x)));
    return ans > pi+eps ? 2*pi-ans : ans;
}

/// Returns angle from positive X
/// If we consider a line from origin to the point P then this function
/// returns the angle between the positive X axis and that line.
double angelFromAxis(Point P){
    double ang = atan2(P.y, P.x);
    if(ang+eps<0.0) ang += 2.0*pi;
    return ang;
}
/// Rotate the point p by "angle" degree with respect to the point a
Point rotatePoint(Point a, double angle, Point p){
    double s = sin(angle);
    double c = cos(angle);
    // translate point back to origin:
    p.x -= a.x;
    p.y -= a.y;
    // rotate point
    double xnew = p.x * c - p.y * s;
    double ynew = p.x * s + p.y * c;
    // translate point back to initial:
    p.x = xnew + a.x;
    p.y = ynew + a.y;
    return p;
}
///……...……….Geo Line…………………………
/// Line Geometry
/// Use necessary functions related to line
/// Don't forget to include base template
struct lineGeometry{
    /// Returns A,B,C of the equation Ax + By = C.
    piii lineEquation(Point P1, Point P2){
        int A = P2.y - P1.y;
        int B = P1.x - P2.x;
        int C = A * P1.x + B * P1.y;
        return MP(MP(A,B), C);
    }
    /// Find minimum distance between C and line/segment (A - B)
    double pointToLineDistance(Point A, Point B, Point C, bool isSeg) {
        double d = (double)crossABC(A, B, C) / dist(A, B);
        if (isSeg) { /// AB is a line segment
            if (dotABC(A, B, C) > 0) return dist(B, C);
            if (dotABC(B, A, C) > 0) return dist(A, C);
        }
        return FABS(d);
    }
    /// Check if R lies on line segment (P - Q)
    bool onSegment(Point P, Point Q, Point R) {
        if (R.x >= min(P.x, Q.x) && R.x <= max(P.x, Q.x) &&
                R.y >= min(P.y, Q.y) && R.y <= max(P.y, Q.y)){
            return true;
        } else {
            return false;
        }
    }
    /// Check if line segment (P1-P2) and line segment (P3-P4) intersect
    bool segmentIntersect(Point P1, Point P2, Point P3, Point P4) {
        int o1 = orientation(P1, P2, P3);
        int o2 = orientation(P1, P2, P4);
        int o3 = orientation(P3, P4, P1);
        int o4 = orientation(P3, P4, P2);
        if (o1 != o2 && o3 != o4 && o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0){
            return true;
        }
        if (o1 == 0 && onSegment(P1, P2, P3)) return true;
        if (o2 == 0 && onSegment(P1, P2, P4)) return true;
        if (o3 == 0 && onSegment(P3, P4, P1)) return true;
        if (o4 == 0 && onSegment(P3, P4, P2)) return true;
        return false;
    }
    /// Find intersection point of line (P1-P2) and (P3-P4)
    void intersectionPoint(Point P1, Point P2, Point P3, Point P4){
        piii L1 = lineEquation(P1,P2);
        int A1 = L1.ff.ff, B1 = L1.ff.ss, C1 = L1.ss;
        piii L2 = lineEquation(P3,P4);
        int A2 = L2.ff.ff, B2 = L2.ff.ss, C2 = L2.ss;
        int dif = A1*B2 - A2*B1; /// Slope difference of the two lines
        if(dif == 0){ /// Lines are either collinear or parallel.
            vector<Point> List;
            List.pb(P1); List.pb(P3); List.pb(P4); List.pb(P2);
            if (polygonArea(List) == 0){
                printf("Collinear\n");
            }else{
                printf("Parallel\n");
            }
        }else{
            double x = (B2 * C1 - B1 * C2) / dif;
            double y = (A1 * C2 - A2 * C1) / dif;
            cerr << x << " " << y << endl; /// Return if needed.
        }
    }
    /// Find a point C on line AB such that distance from A to C is D.
    Point pointAtDistanceD(Point A, Point B, double D){
        Point vecAB,C;
        vecAB.x = B.x - A.x;
        vecAB.y = B.y - A.y;
        double norm = sqrt(SQ(vecAB.x) + SQ(vecAB.y));
        vecAB.x /= norm;
        vecAB.y /= norm;
        C.x = A.x + D*vecAB.x; /// To find a point D distance away but outside the line then minus here.
        C.y = A.y + D*vecAB.y;
        return C;
    }
}lineGeo;
///………………….Geo Circle…………………………..
/// Circle Geometry
/// Use necessary functions related to circle
/// Don't forget to include base template
struct circleGeometry{
    /// Find the intersection points of a line and a circle
    /// Parameters: Circle center, radius, line end points P1 and P2
    pair<Point,Point> lineCircleIntersectionPoints(Point center, double r, Point P1, Point P2){
        double a1 = P2.x - P1.x;
        double a2 = P2.y - P1.y;
        double b1 = P1.x - center.x;
        double b2 = P1.y - center.y;
        // At^2 + Bt + C = 0
        double A = SQ(a1) + SQ(a2);
        double B = (a1*b1 + a2*b2)*2;
        double C = SQ(b1) + SQ(b2) - SQ(r);
        if((B*B - 4.0*A*C)<0){
            /// Does not intersect
        }else if((B*B - 4.0*A*C) == 0){
            /// The line is tangent with the circle at a single point
        }else{
            /// The line intersect the circle at two points
            double t1 = (-B - sqrt(B*B - 4.0*A*C))/2.0/A;
            double t2 = (-B + sqrt(B*B - 4.0*A*C))/2.0/A;

            Point E1 = {P1.x + a1*t1, P1.y + a2*t1};
            Point E2 = {P1.x + a1*t2, P1.y + a2*t2};
            return MP(E1,E2);
        }
    }
    /// Find intersected area of two circles
    /// Parameters:1st circle center, radius, 2nd circle center, radius
    double circleCircleIntersectionArea(Point P0, double R0, Point P1, double R1) {
        double d = dist(P0, P1);
        if(R0 + R1 <= d) return 0;
        if(R0 >= R1 && (R0 - R1) >= d) return pi * SQ(R1);
        if(R0 <= R1 && (R1 - R0) >= d) return pi * SQ(R0);
        double CAD = 2.0 * acos((SQ(R0) + SQ(d) - SQ(R1)) / (2.0 * R0 * d));
        double CBD = 2.0 * acos((SQ(R1) + SQ(d) - SQ(R0)) / (2.0 * R1 * d));
        //double A1 = (0.5 * SQ(R0) * CAD) - (0.5 * SQ(R0) * sin(CAD));
        double A1 = 0.5 * SQ(R0) * (CAD - sin(CAD));
        //double A2 = (0.5 * SQ(R1) * CBD) - (0.5 * SQ(R1) * sin(CBD));
        double A2 = 0.5 * SQ(R1) * (CBD - sin(CBD));
        return (A1 + A2);
    }
    /// Find intersection points of two circles
    /// Parameters: 1st circle center, radius, 2nd circle center, radius
    void circleCircleIntersectionPoints(Point P0, double R0, Point P1, double R1) {
        double d = dist(P0, P1);
        if(d > R0 + R1){
            /// They don't intersect.

        }else if(d < FABS(R0 - R1)){
            /// One fully contains the other one.
        }else if(FABS(d - 0)<eps && R0 == R1){
            /// Both are same circle.
        }else{
            /// The circles intersect with each other
            double a = (SQ(R0) - SQ(R1) + SQ(d))/(2.0 * d);
            double b = d - a;
            double h = sqrt(SQ(R0) - SQ(a));
            double rx = -(P1.y - P0.y) * (h/d);
            double ry = (P1.x - P0.x) * (h/d);
            Point P2;
            P2.x = P0.x + (a * (P1.x - P0.x))/d;
            P2.y = P0.y + (a * (P1.y - P0.y))/d;
            Point E1 = {P2.x + rx, P2.y + ry};
            Point E2 = {P2.x - rx, P2.y - ry};
            /// E1, E2 are the intersection points. Return if needed.
        }
    }
    /// Find the center of the circle which pass through point a & b having radius R.
    void findCenterGivenTwoPointsOnIt(Point a,Point b,double R) {
        Point g1,g2;
        double x1 = a.x, x2 = b.x;
        double y1 = a.y, y2 = b.y;
        double d = dist(a, b);
        if (d * d > 4.0 * R * R) {
            /// Not Possible to Find any Center;
            return;
        }
        double x_part = sqrt(R * R - 0.25 * d * d) * (y1 - y2) / d;
        double y_part = sqrt(R * R - 0.25 * d * d) * (x2 - x1) / d;
        double x3 = 0.5 * (x1 + x2), y3 = 0.5 * (y1 + y2);
        g1 = Point(x3 + x_part, y3 + y_part); /// One possible center
        g2 = Point(x3 - x_part, y3 - y_part); /// Another possible center
    }
    /// Given 3 points A, B, C on the circumference of a circle
    /// Find the center of that circle
    Point circleCenter(Point A, Point B, Point C) {
        double yDelta_a = B.y - A.y;
        double xDelta_a = B.x - A.x;
        double yDelta_b = C.y - B.y;
        double xDelta_b = C.x - B.x;
        Point center = Point(0.0, 0.0);
        double aSlope = yDelta_a/xDelta_a;
        double bSlope = yDelta_b/xDelta_b;
        center.x = (aSlope*bSlope*(A.y - C.y) + bSlope*(A.x + B.x)
                    - aSlope*(B.x + C.x) )/(2* (bSlope - aSlope));
        center.y = -1*(center.x - (A.x + B.x)/2)/aSlope +  (A.y + B.y)/2;
        return center;
    }
}circleGeo;
///……...…………..Geo Polygon……………….
/// Polygon Geometry
struct polygonGeometry{
    int N; /// Number of total points
    vector<Point> polygon; /// Contains all the polygon points
    void clear(){
        polygon.clear();
    }
    bool onSegment(Point P, Point Q, Point R){
        if (R.x >= min(P.x, Q.x) && R.x <= max(P.x, Q.x) && R.y >= min(P.y, Q.y)
                && R.y <= max(P.y, Q.y)){
            return true;
        }else{
            return false;
        }
    }
    bool doIntersect(Point P1, Point P2, Point P3, Point P4, bool &onLine){
        int o1 = orientation(P1, P2, P3);
        int o2 = orientation(P1, P2, P4);
        int o3 = orientation(P3, P4, P1);
        int o4 = orientation(P3, P4, P2);
        if (o1 != o2 && o3 != o4 && o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0){
            return true;
        }
        if (o1 == 0 && onSegment(P1, P2, P3)){
            onLine = true; /// Change, if point on line is not allowed
            return true;
        }
        if (o2 == 0 && onSegment(P1, P2, P4)) return true;
        if (o3 == 0 && onSegment(P3, P4, P1)) return true;
        if (o4 == 0 && onSegment(P3, P4, P2)) return true;
        return false;
    }
    /// Check if point P lie inside polygon
    bool isInsidePolygon(Point P) {
        Point Q;
        Q.y = P.y + 1e9; /// Change here, depends on maximum co ordinate value
        Q.x = P.x + 1e9+1;
        bool onLine = false; /// To check if the point lie on any segment
        int cnt = 0;
        for (int i = 0; i + 1 < polygon.size(); i++){
            if (doIntersect(polygon[i], polygon[i + 1], P, Q, onLine)) cnt++;
        }
        if (onLine) return true; /// Change here, if point on line is not allowed
        if (cnt % 2 == 1) return true;
        return false;
    }
    /// Given a convex hull it returns the center of mass/grav of it
    Point centerOfMass(vector<Point> P) {
        double area = polygonArea(P);
        double cx = 0, cy = 0;
        int sz = P.size();
        for (int i = 0; i < sz; ++i) {
            Point cur = P[i];
            Point nxt = P[(i + 1) % sz];
            cx += (cur.x + nxt.x) * (cur.x * nxt.y - cur.y * nxt.x);
            cy += (cur.y + nxt.y) * (cur.x * nxt.y - cur.y * nxt.x);
        }
        cx = cx/(6.0 * area);
        cy = cy/(6.0 * area);
        return Point(cx, cy);
    }
}polygonGeo;
///………………..Convex Hull…………………
/// Convex Hull
/// Take input points in polygon vector and assign N
/// Call grahamScan to get convex hull in vector hull
Point lowerLeft;
bool convexCmp(Point X, Point Y) {
    LL ret = orientation(lowerLeft, X, Y);
    if (ret == 0) {
        LL d1 = sqrDist(lowerLeft, X);
        LL d2 = sqrDist(lowerLeft, Y);
        return (d1 < d2);
    } else if (ret == 2){
        return true;
    } else {
        return false;
    }
}
struct convexHull{
    int N; /// Number of total points
    stack<Point> st;
    vector<Point> polygon; /// Contains all the polygon points
    vector<Point> hull; /// Convex hull points (all distinct)
    /// Reverse hull depending on necessity
    void clear(int L){
        polygon.clear();
        hull.clear();
        N = L;
    }
    Point nextToTop() {
        Point P = st.top();
        st.pop();
        Point res = st.top();
        st.push(P);
        return res;
    }
    void grahamScan(){
        int ymin = polygon[0].y, idx = 0;
        for (int i = 1; i < N; i++) {
            if (polygon[i].y < ymin || (polygon[i].y == ymin &&
                            polygon[i].x < polygon[idx].x)) {
                ymin = polygon[i].y;
                idx = i;
            }
        }
        swap(polygon[0], polygon[idx]);
        lowerLeft = polygon[0];
        sort(polygon.begin()+1, polygon.end(), convexCmp);
        st.push(polygon[0]);
        for (int i = 1; i < N; i++) {
            while (st.size() > 1){
                if(orientation(nextToTop(),st.top(), polygon[i]) == 2) break;
                st.pop();
            }
            st.push(polygon[i]);
        }
        while (!st.empty()) {
            hull.pb(st.top());
            st.pop();
        }
    }
}convexhull;

