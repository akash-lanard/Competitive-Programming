#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff first
#define ss second
typedef pair<int, string> pis;

#define SIZE 105/// change SIZE if needed (won't work for big value tho)

int n;          /// size of array
pis dp[SIZE];   /// dp array
int val[SIZE];  /// value array (made from given string)
int dir[SIZE];  ///direction array
string S;       /// given string

void pre() {
    for(int i=0; i<n; i++) {
        val[i] = (S[i] - 'a');     /// change accordingly (done for small letters only)
    }
}

pis longest(int curr) {
    if(dp[curr].ff!=-1) {
        return dp[curr];
    }
    pis mx = pis(0, "");
    for(int i=curr+1; i<n; i++) {  /// 0 indexed
        if(val[i]>val[curr]) {
            pis temp = longest(i);
            if(temp.ff>mx.ff) {
                mx = temp;
                dir[curr] = i;
            }
            else if(temp.ff==mx.ff) {
                if(temp.ss<mx.ss) {
                    mx = temp;
                    dir[curr] = i;
                }
            }
        }
    }
    string retStr = S[curr] + mx.ss;
    dp[curr] = pis(mx.ff+1, retStr);
    return dp[curr];
}

pis LIS() {
    int start = -1;
    pis ret = pis(0, "");
    for(int i=0; i<n; i++) { /// 0 indexed
        pis temp = longest(i);
        if(temp.ff>ret.ff) {
            ret = temp;
            start = i;
        }
        else if(temp.ff==ret.ff) {
            if(temp.ss<ret.ss) {
                ret = temp;
                start = i;
            }
        }
    }
    return ret;     /// also return start if needed
}

void clr() {
    for(int i=0; i<SIZE; i++) {
        dp[i].first = -1;
    }
    memset(dir, -1, sizeof(dir));
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    clr();          /// clear dp and dir array

    cin >> S;       /// given string
    n = S.size();   /// length of string

    pre();
    pis ret = LIS();  /// first = lex min LIS length, second = lex min LIS string

    cout << ret.first << ", " << ret.second << endl;

    return 0;
}
