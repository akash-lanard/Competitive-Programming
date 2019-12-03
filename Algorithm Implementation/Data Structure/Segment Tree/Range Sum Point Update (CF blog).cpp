/// Source: https://codeforces.com/blog/entry/15729

#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

#define SIZE 100005     /// Modify size if needed

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

/// Build function to build the segment tree. Call build()
void build(int id = 1, int l = 0, int r = N) {
    if(r-l<2) {                 /// Reached at the leaf node
        S[id] = A[l];
        return;
    }

    int mid = (l+r)/2;          /// Split into two segments
    build(id*2, l, mid);        /// Build left child
    build(id*2+1, mid, r);      /// Build right child
    S[id] = S[id*2] + S[id*2+1];/// Build current node
}


/// Update function to modify the elements. Call modify(p, x)
void modify(int p, int x, int id = 1, int l = 0, int r = N) {
    S[id] += (x - A[id]);               /// Update current node's sum
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
    if(x<=l && r<=y) return S[id];      /// Completyly inside
    int mid = (l+r)/2;                  /// Split into 2 segments
    return sum(x, y, 2*id, l, mid) + sum(x, y, 2*id+1, mid, r); /// Get sum from both child
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    cin >> N;               /// Number of elements
    for(int i=0; i<N; i++) {
        cin >> A[i];        /// get the elements
    }

    build();                /// build segment tree from the elements

    int Q;                  /// Number of queries
    cin >> Q;
    for(int i=0; i<Q; i++) {
        char ch;
        cin >> ch;          /// Get query type
        if(ch=='S') {       /// Query type 1 (range sum)
            int l, r;
            cin >> l >> r;  /// l and r are 0-indexed [r is not included in the sum]
            cout << sum(l, r) << "\n";
        }
        else if(ch=='M') {  /// Query type 2 (point update)
            int p, x;       /// p is 0-indexed
            cin >> p >> x;
            modify(p, x);
        }
    }

    return 0;
}
