/// Source: https://codeforces.com/blog/entry/15890
/// Problem link: https://www.spoj.com/problems/KQUERYO/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL)

#define SIZE 30005 /// change size if needed

int N; /// Number of elements
int A[SIZE]; /// given array
vector<int> V[4*SIZE]; /// Each node represents a vector (elements of this range in sorted order)

void build(int id=1, int l=0, int r = N) { /// call build() after taking input
    if(r-l<2) {
        V[id].pb(A[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid, r); /// Merge sort this two sorted arrays
    merge(V[2*id].begin(), V[2*id].end(), V[2*id+1].begin(), V[2*id+1].end(), back_inserter(V[id]));
}

int query(int x, int y, int k, int id=1, int l=0, int r=N) { /// Number of elements greater than k in [x, y)
    if(x>=r || y<=l) return 0;
    if(x<=l && r<=y) { /// do it differently for different condition
        return V[id].size() - (upper_bound(V[id].begin(), V[id].end(), k) - V[id].begin());
    }
    int mid = (l+r)/2;
    return query(x, y, k, 2*id, l, mid) + query(x, y, k, 2*id+1, mid, r);
}

int main() {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    build();

    int q;
    cin >> q;
    int lastAns = 0;
    for(int i=0; i<q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int I = a^lastAns, J = b^lastAns, K = c^lastAns;
        if(I<1) I = 1;
        if(J>N) J = N;
        if(I>J) {
            cout << "0\n";
            lastAns = 0;
            continue;
        }
        int ret = query(I-1, J, K);
        cout << ret << "\n";
        lastAns = ret;
    }

    return 0;
}
