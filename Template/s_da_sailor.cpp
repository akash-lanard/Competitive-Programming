///====================== TEMPLATE STARTS HERE =====================///
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define POPCOUNT __builtin_popcountll
#define Set(N,p) N=((N)|((1LL)<<(p)))
#define Reset(N,p) N=((N)&(~((1LL)<<(p))))
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

int ks;

void solve() {

}

int main () {
    #ifdef s_da_sailor
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // s_da_sailor

    fast_cin;

    int tc;
    cin >> tc;

    for(ks=1; ks<=tc; ks++) {
        solve();
    }

    return 0;
}
