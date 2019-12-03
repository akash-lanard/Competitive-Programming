/// Source: https://codeforces.com/blog/entry/15729

#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

#define SIZE 100005     /// Modify size if needed

/// Basic segment tree (with lazy)
/// Each node denotes the range [l, r) [Note: r is not included]
/// S[l, r) = S[l, mid) + S[mid, r)
/// Range sum range update
/// 2 types of queries:
/// 1. S l r: Sum in range from l to r  [Note: r is not included]
/// 2. I l r x: Increase the values of index l to r to x [Note: r is not included]

int N;              /// Number of elements
int A[SIZE];        /// Elements (0-indexed)
int S[4*SIZE];      /// Nodes in segment tree
int lazy[4*SIZE];   /// Lazy array (for nodes)

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

/// Function to update a node
void upd(int id, int l, int r, int x) {
    lazy[id] += x;              /// Increase all members in this interval by x
    S[id] += (r-l)*x;
}

/// Function to pass update information to its children
void shift(int id, int l, int r) {
    int mid = (l+r)/2;
    upd(id*2, l, mid, lazy[id]);    /// Pass update info to left child
    upd(id*2+1, mid, r, lazy[id]);  /// Pass update info to right child
    lazy[id] = 0;                   /// Passing is done
}

/// Update function to perform increase queries. Call increase(l, r, x)
void increase(int x, int y, int v, int id = 1, int l = 0, int r = N) {
    if(r<=x || y<=l) return;            /// Completely outside (no need to update)
    if(x<=l && r<=y) {                  /// Completely inside
        upd(id, l, r, v);               /// Update lazy
        return;                         /// No need to update further
    }
    shift(id, l, r);                    /// Pass update info to the children
    int mid = (l+r)/2;
    increase(x, y, v, 2*id, l, mid);    /// Update left child
    increase(x, y, v, 2*id+1, mid, r);  /// Update right child
    S[id] = S[2*id] + S[2*id+1];        /// Update current node
}

/// Query function to get sum. Call sum(l, r)
int sum(int x, int y, int id = 1, int l = 0, int r = N) {
    if(r<=x || y<=l) return 0;      /// Completely outside
    if(x<=l && r<=y) return S[id];  /// Completely inside
    shift(id, l, r);                /// Pass update info to the children
    int mid = (l+r)/2;
    return sum(x, y, 2*id, l, mid) + sum(x, y, 2*id+1, mid, r); /// get sum from both child
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    cin >> N;                   /// Number of elements
    for(int i=0; i<N; i++) {
        cin >> A[i];            /// Get the elements
    }

    build();                    /// Build the segment tree form the elements

    int Q;                      /// Number of queries
    cin >> Q;
    for(int i=0; i<Q; i++) {
        char ch;                /// Get Query type
        cin >> ch;
        if(ch=='S') {           /// Query type 1 (range sum)
            int l, r;
            cin >> l >> r;
            cout << sum(l, r) << "\n";
        }
        else if(ch=='I') {      /// Query type 2 (range update)
            int l, r, x;
            cin >> l >> r >> x;
            increase(l, r, x);
        }
    }


    return 0;
}
