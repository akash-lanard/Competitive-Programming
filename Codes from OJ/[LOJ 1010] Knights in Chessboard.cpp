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
 
    int tc;
 
    scanf("%d", &tc);
 
    for(int i=0; i<tc; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a>b) swap(a, b);
 
        int ans=0;
        if(a==1) {
            ans = b;
        }
        else if(a==2) {
            if(b==2) {
                ans = 4;
            }
            else if(b%2==0) {
                if(b%4==0) {
                    ans = (a*b)/2;
                }
                else {
                    ans = b+2;
                }
            }
            else {
                ans = b+1;
            }
        }
        else if(a%2==1 && b%2==1) {
            ans = ((a*b)/2)+1;
        }
        else {
            ans = (a*b)/2;
        }
 
        printf("Case %d: %d\n", i+1, ans);
    }
 
 
    return 0;
}
