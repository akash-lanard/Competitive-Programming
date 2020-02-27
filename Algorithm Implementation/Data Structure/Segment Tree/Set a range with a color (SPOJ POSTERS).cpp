/// Source: https://codeforces.com/blog/entry/15890
/// Problem link: https://www.spoj.com/problems/POSTERS/

#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

#define SIZE 10000005   /// Update size if needed

int N;  /// Number of nodes
int lazy[4*SIZE]; /// Lazy array (Only it is needed)

void shift(int id) { /// Shift info to its children
    if(lazy[id]) {
        lazy[2*id] = lazy[2*id+1] = lazy[id];
    }
    lazy[id] = 0;
}

void upd_set(int x, int y, int col, int id=1, int l=0, int r=N) { /// Set range [x,y) with color col
    if(x>=r || y<=l) return;
    if(x<=l && r<=y) {
        lazy[id] = col;
        return;
    }
    int mid = (l+r)/2;
    shift(id);
    upd_set(x, y, col, 2*id, l, mid);
    upd_set(x, y, col, 2*id+1, mid, r);
}

set<int> se;
void get_cnt(int id=1, int l=0, int r=N) { /// get count (no of different colors: se.size() )
    if(lazy[id]) {
        se.insert(lazy[id]);
        return;
    }
    if(r-l<2) return;
    int mid = (l+r)/2;
    get_cnt(2*id, l, mid);
    get_cnt(2*id+1, mid, r);
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    int tc;
    cin >> tc;
    for(int ks=1; ks<=tc; ks++) {
        memset(lazy, 0, sizeof(lazy));
        se.clear();
        N = 10000000;
        int n;
        cin >> n;
        for(int i=1; i<=n; i++) {
            int l, r;
            cin >> l >> r;
            upd_set(l-1, r, i);
        }
        get_cnt();
        cout << se.size() << "\n";
    }

    return 0;
}
