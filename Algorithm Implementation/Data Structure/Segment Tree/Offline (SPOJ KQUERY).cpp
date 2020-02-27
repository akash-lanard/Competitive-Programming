/// Problem link: https://www.spoj.com/problems/KQUERY/
/// Source: https://codeforces.com/blog/entry/15890
/// Did it a bit differently

#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MP make_pair
#define ff first
#define ss second

/// Need to solve it offline
/// Sort the values of the elements and queries (I did in decreasing order)
/// Initially the all the values of the nodes is 0, increasing it when needed
/// Derives it to simple range sum query with point update
/// Need the modify() and sum() function as it is

typedef pair<int, int> pii;
typedef pair<pii, pii> qr;              /// Query (l, r, k, indx)

bool comp(const qr &a, const qr &b) {   /// Comparator for query vector
    return a.ss.ff>b.ss.ff;
}

bool comp2(const pii &a, const pii &b) {/// Comparator for V vector
    return a.ff>b.ff;
}

vector<qr> qVec;        /// Query vector (l, r, k, indx)
vector<pii> V;          /// Given values with index

int ans[200005];        /// Save the answers according to query index

/// .............Basic Segment Tree code......................
/// Only modify and sum functions are needed as it is

#define SIZE 200005     /// Modify size if needed

/// Basic segment tree
/// Each node denotes the range [l, r) [Note: r is not included]
/// S[l, r) = S[l, mid) + S[mid, r)
/// Range sum point update
/// 2 types of queries:
/// 1. S l r: Sum in range from l to r [Note: r is not included]
/// 2. M p x: Modify the value of index-p to x

int N;          /// Number of elements
int A[SIZE];    /// Elements (0-indexed)
int S[4*SIZE];  /// Nodes in segment tree


/// Update function to modify the elements. Call modify(p, x)
void modify(int p, int x, int id = 1, int l = 0, int r = N) {
    S[id] += (x - A[p]);               /// Update current node's sum
    if(r-l<2) {
        A[p] = x;                       /// Reached at the leaf node
        return;
    }

    int mid = (l+r)/2;                  /// Get the mid value
    if(p<mid) {                         /// The index is in left child
        modify(p, x, 2*id, l, mid);     /// Modify left
    }
    else {                              /// The index is in right child
        modify(p, x, 2*id+1, mid, r);   /// Modify right
    }
}

/// Query function for getting the range sum. Call sum(l, r) [Note: r is not included in the sum]
int sum(int x, int y, int id = 1, int l = 0, int r = N) {
    if(r<=x || y<=l) return 0;          /// Completely outside
    if(x<=l && r<=y) return S[id];      /// Completely inside
    int mid = (l+r)/2;                  /// Split into 2 segments
    return sum(x, y, 2*id, l, mid) + sum(x, y, 2*id+1, mid, r); /// Get sum from both child
}
///..........................................................................................

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    cin >> N;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        V.push_back(pii(a, i));
    }

    sort(V.begin(), V.end(), comp2);        /// Sort the values

    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        qVec.push_back(MP(pii(l, r), pii(k, i)));
    }

    sort(qVec.begin(), qVec.end(), comp);   /// Sort the queries

    int curr = 0;
    for(int i=0; i<qVec.size(); i++) {      /// Solve it offline and save
        while(curr<V.size() && V[curr].ff>qVec[i].ss.ff) {
            modify(V[curr].ss, 1);
            curr++;
        }

        int ret = sum(qVec[i].ff.ff-1, qVec[i].ff.ss);  /// Note the index

        ans[qVec[i].ss.ss] = ret;
    }

    for(int i=0; i<Q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
