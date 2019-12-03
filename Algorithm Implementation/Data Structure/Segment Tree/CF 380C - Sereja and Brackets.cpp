/// Problem link: https://codeforces.com/contest/380/problem/C
/// Source: https://codeforces.com/blog/entry/15890

#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff first
#define ss second

#define SIZE 1000005    /// Max number of elements

/// For each node (for example x), we keep three integers:
/// 1.T[x] = Answer for it's interval.
/// 2. O[x] = The number of '('s after deleting the brackets
/// who belong to the correct bracket sequence in this interval with length T[x].
/// 3. C[x] = The number of ')'s after deleting the brackets
/// who belong to the correct bracket sequence in this interval with length T[x].

/// Lemma : For merging to nodes 2x and 2x+1 (children of node x) all we need to do is this:
/// tmp = min(O[2 * x], C[2 * x + 1])
/// T[x] = T[2 * x] + T[2 * x + 1] + tmp
/// O[x] = O[2 * x] + O[2 * x + 1] - tmp
/// C[x] = C[2 * x] + C[2 * x + 1] - tmp

/// [Note: every node contains the range [l, r). r is not included]

int N;              /// Number of elements
string S;           /// Given string
int T[4*SIZE];      /// Answer for this interval (length of the maximum subsequence)
int O[4*SIZE];      /// Number of '(' that does not belong to the subsequence in this interval
int C[4*SIZE];      /// Number of ')' that does not belong to the subsequence in this interval

/// Build function
void build(int id = 1, int l = 0, int r = N) {
    if(r-l < 2) {                       /// Reached leaf node
        if(S[l]=='(') {
            O[id] = 1;
            C[id] = 0;
            T[id] = 0;
        }
        else {
            C[id] = 1;
            O[id] = 0;
            T[id] = 0;
        }
        return;
    }

    int mid = (l+r)/2;
    build(2*id, l, mid);                /// Build left child
    build(2*id+1, mid, r);                /// Build right child

    int tmp = min(O[2*id], C[2*id+1]);  /// Build current node
    T[id] = T[2*id] + T[2*id+1] + tmp;
    O[id] = O[2*id] + O[2*id+1] - tmp;
    C[id] = C[2*id] + C[2*id+1] - tmp;
}

typedef pair<int, int> pii;
typedef pair<int, pii> node;

/// Query function. It returns 3 variables (T, O, C)
node segment(int x, int y, int id = 1, int l = 0, int r = N) {
    if(r<=x || y<=l) return node(0, pii(0, 0));             /// Completely outside
    if(x<=l && r<=y) return node(T[id], pii(O[id], C[id])); /// Completely inside

    int mid = (l+r)/2;
    node a = segment(x, y, 2*id, l, mid);                   /// Get values of left child
    node b = segment(x, y, 2*id+1, mid, r);                 /// Get values of right child

    int tmp = min(a.ss.ff, b.ss.ss);                        /// Get values of current node accordingly
    int t = a.ff + b.ff + tmp;
    int o = a.ss.ff + b.ss.ff - tmp;
    int c = a.ss.ss + b.ss.ss - tmp;

    return node(t, pii(o, c));
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    cin >> S;                                       /// Get the string
    N = S.size();                                   /// Set N

    build();                                        /// Build segment tree

    int Q;
    cin >> Q;                                       /// Number of queries
    for(int i=0; i<Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << 2*segment(l-1, r).ff << "\n";       /// Get the length
    }

    return 0;
}
