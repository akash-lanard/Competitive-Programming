/// Source: https://codeforces.com/blog/entry/15890

#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL)

/**
Problem :
We have n vectors, v1,v2,..,vn and all of them are initially empty. We should perform m queries on this vectors of two types :
1. A p k Add number k at the end of vp
2. C l r k print the number of occurrence of k from lth to rth vector (summation of occurrences)
*/

#define SIZE 100005 /// Change size if needed

int N;  /// number of vectors
multiset<int> S[4*SIZE]; /// Nodes of the segment tree

/// adds k to pth vector
void add(int p, int k, int id=1, int l=0, int r=N) {
    S[id].insert(k);
    if(r-l<2) return;
    int mid = (l+r)/2;
    if(p<mid) {
        add(p, k, 2*id, l, mid);
    }
    else {
        add(p, k, 2*id+1, mid, r);
    }
}

/// number of occurrence of k from lth to rth vector (summation of occurrences)
int query(int x, int y, int k, int id=1, int l=0, int r=N) {
    if(x>=r || y<=l) return 0;
    if(x<=l && r<=y) return S[id].count(k);
    int mid = (l+r)/2;
    return query(x, y, k, 2*id, l, mid) + query(x, y, k, 2*id+1, mid, r);
}

int main() {
    #ifdef forthright48
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // forthright48

    fast_cin;

    int q;
    cin >> N >> q;
    for(int i=0; i<q; i++) {
        string str;
        cin >> str;
        if(str=="A") {
            int p, k;
            cin >> p >> k;
            add(p-1, k);
        }
        else if(str=="C") {
            int l, r, k;
            cin >> l >> r >> k;
            int ret = query(l-1, r, k);
            cout << ret << "\n";
        }
    }

    return 0;
}
