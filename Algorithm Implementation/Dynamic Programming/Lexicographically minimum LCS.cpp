#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff first
#define ss second
typedef pair<int, string> pis;

#define SIZE 105    /// change SIZE if needed (won't work for big value tho)

string A, B;        /// given strings
int lenA, lenB;     /// lengths
pis dp[SIZE][SIZE]; /// dp array

///calculate LCS
pis calcLCS(int i, int j)
{
    if(i==lenA || j==lenB) {
        dp[i][j].ff = 0;
        dp[i][j].ss = "";
        return dp[i][j];
    }
    if(dp[i][j].ff!=-1) return dp[i][j];

    pis ans = pis(0, "");
    if(A[i]==B[j]) {
        pis temp = calcLCS(i+1, j+1);
        string str = "";
        str += A[i];
        str += temp.ss;
        ans = pis(temp.ff+1, str);
    }
    else {
        pis temp1 = calcLCS(i+1, j);
        pis temp2 = calcLCS(i, j+1);

        if(temp1.ff>temp2.ff) {
            ans = temp1;
        }
        else if(temp1.ff<temp2.ff) {
            ans = temp2;
        }
        else {
            if(temp1.ss<temp2.ss) {
                ans = temp1;
            }
            else {
                ans = temp2;
            }
        }
    }

    dp[i][j] = ans;
    return ans;
}

///clear function
void clr()
{
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            dp[i][j].ff = -1;
            dp[i][j].ss = "";
        }
    }
}


int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    cin >> A >> B;

    lenA = A.size();
    lenB = B.size();

    clr();
    pis ret = calcLCS(0, 0);      /// lex min LCS

    cout << ret.ff << ", " << ret.ss << "\n";

    return 0;
}
