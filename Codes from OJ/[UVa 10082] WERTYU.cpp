///====================== TEMPLATE STARTS HERE =====================///
#include <bits/stdc++.h>
using namespace std;

/// Verdict: AC

//#include <ext/pb_ds/assoc_container.hpp> // Include for built in treap
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//#include <sys/resource.h>     // for linux stack memory increase
//#define gc getchar_unlocked   // for linux fast io
//#define gc getchar            // for windows fast io

#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define nl puts("")
#define sp printf(" ")
#define phl debug("Hello")
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((vlong)(x).size())
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define SQ(x) ((x)*(x))
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define NORM(x) if(x>=mod) x-=mod;if(x<0) x+=mod;
#define ODD(x) (((x)&1)==0?(0):(1))
#define Set(N,p) N=((N)|((1LL)<<(p)))
#define Reset(N,p) N=((N)&(~((1LL)<<(p))))
#define Check(N,p) (!(((N)&((1LL)<<(p)))==(0)))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define arrayIndexPrint(A,i) cerr<<"~ At pos: "<<i<<" = "<<A[i]
#define dump(x) cerr<<"~ "<<#x<<" = "<<x<<endl
#define arrayPrint(A,st,ed) cerr<<"~ Array:";FOR(i,st,ed) cerr<<" "<<A[i];cerr<<endl
#define LINE cerr<<"\n"; FOR(i,0,50) cerr<<"=";cerr<<"\n\n"

#define LL long long
#define LLU long long unsigned int
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<int> vi;
typedef vector<vlong> vl;
typedef vector<pll> vll;
//typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);

#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
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

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1; /// For bigmod2 multiply here using mulmod
    }
    return res;
}


//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//int dir8[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-11;

///======================  TEMPLATE ENDS HERE  =====================///


int main () {
    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //fast_cin;

    map<string, string> mymap;

    mymap["W"] = "Q";
    mymap["E"] = "W";
    mymap["R"] = "E";
    mymap["T"] = "R";
    mymap["Y"] = "T";
    mymap["U"] = "Y";
    mymap["I"] = "U";
    mymap["O"] = "I";
    mymap["P"] = "O";
    mymap["["] = "P";
    mymap["]"] = "[";
    mymap["\\"] = "]";

    mymap["S"] = "A";
    mymap["D"] = "S";
    mymap["F"] = "D";
    mymap["G"] = "F";
    mymap["H"] = "G";
    mymap["J"] = "H";
    mymap["K"] = "J";
    mymap["L"] = "K";
    mymap[";"] = "L";
    mymap["'"] = ";";

    mymap["X"] = "Z";
    mymap["C"] = "X";
    mymap["V"] = "C";
    mymap["B"] = "V";
    mymap["N"] = "B";
    mymap["M"] = "N";
    mymap[","] = "M";
    mymap["."] = ",";
    mymap["/"] = ".";

    mymap["1"] = "`";
    mymap["2"] = "1";
    mymap["3"] = "2";
    mymap["4"] = "3";
    mymap["5"] = "4";
    mymap["6"] = "5";
    mymap["7"] = "6";
    mymap["8"] = "7";
    mymap["9"] = "8";
    mymap["0"] = "9";
    mymap["-"] = "0";
    mymap["="] = "-";

    mymap[" "] = " ";

    string line;

    while(getline(cin, line)) {
        string line2 = "";
        for(int i=0; i<line.size(); i++) {
            string temp = "";
            temp += line[i];

            line2 += mymap[temp];
        }
        cout << line2 << endl;
    }

    return 0;
}
