///====================== TEMPLATE STARTS HERE =====================///
#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

#ifdef forthright48
    #include <ctime>
    clock_t tStart = clock();
    #define debug(args...) {dbg,args; cerr<<endl;}
    #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
    #define bug printf("%d\n",__LINE__);
#else
    #define debug(args...) //Just strip off all debug tokens
    #define timeStamp
#endif // forthright48

struct debugger{
    template<typename T> debugger& operator, (const T& v) {
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///======================  TEMPLATE ENDS HERE  =====================///



int main()
{
    #ifdef forthright48
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // forthright48

    //fast_cin;


    return 0;
}
