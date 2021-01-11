#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

int ks;
int M, T;
string S, str;

#define SIZE 1025000

int N, Q;

struct SEGMENT_TREE {
    int arr[SIZE], Tree[4*SIZE], Lazy[4*SIZE];

    inline void Init() {
        memset(arr, 0, sizeof(arr));
        memset(Tree, 0, sizeof(Tree));
        memset(Lazy, -1, sizeof(Lazy));
    }
    inline void LazyPropagate(int node, int b, int e) {
        if(Lazy[node] != -1) {
            if(Lazy[node] == 1) Tree[node] = (e-b+1);
            else if(Lazy[node] == 0) Tree[node] = 0;
            else Tree[node] = (e-b+1) - Tree[node];

            if(b != e) {
                if(Lazy[node] != 2) {
                    Lazy[2*node] = Lazy[node];
                    Lazy[2*node + 1] = Lazy[node];
                }
                else {
                    if(Lazy[2*node]==0) Lazy[2*node] = 1;
                    else if(Lazy[2*node]==1) Lazy[2*node] = 0;
                    else if(Lazy[2*node]==2) Lazy[2*node] = -1;
                    else Lazy[2*node] = 2;

                    if(Lazy[2*node + 1]==0) Lazy[2*node + 1] = 1;
                    else if(Lazy[2*node + 1]==1) Lazy[2*node + 1] = 0;
                    else if(Lazy[2*node + 1]==2) Lazy[2*node + 1] = -1;
                    else Lazy[2*node + 1] = 2;
                }
            }
            Lazy[node] = -1;
        }
    }
    inline void Build(int node = 1, int b = 0, int e = N-1) {
        if(b > e) return;
        if(b == e) { Tree[node] = arr[b]; return; }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        Build(left, b, mid);
        Build(right, mid+1, e);
        Tree[node] = Tree[left] + Tree[right];
    }
    inline void Update(int i, int j, int val, int node = 1, int b = 0, int e = N-1) {
        LazyPropagate(node, b, e);
        if(i > e || j < b || b > e) return;
        if(i <= b && j >= e) {
            Lazy[node] = val;
            LazyPropagate(node, b, e);
            return;
        }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        Update(i, j, val, left, b, mid);
        Update(i, j, val, right, mid + 1, e);
        Tree[node] = Tree[left] + Tree[right];
    }
    inline int Query(int i, int j, int node = 1, int b = 0, int e = N-1) {
        LazyPropagate(node, b, e);
        if(i > e || j < b || b > e) return 0;
        if(i <= b && j >= e) {
            return Tree[node];
        }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        int Q1 = Query(i, j, left, b, mid);
        int Q2 = Query(i, j, right, mid+1, e);
        return (Q1 + Q2);
    }

} ST;

void solve() {
    ST.Init();

    cin >> M;
    S = "";
    for(int i=0; i<M; i++) {
        cin >> T;
        cin >> str;
        for(int j=0; j<T; j++) S += str;
    }

    N = S.size();

    for(int i=0; i<N; i++) {
        ST.arr[i] = S[i] - '0';
    }

    ST.Build();

    cout << "Case " << ks << ":" << endl;
    cin >> Q;
    int qnum = 1;
    for(int i=1; i<=Q; i++) {
        string ty;
        int a, b;
        cin >> ty >> a >> b;
        if(ty=="F") ST.Update(a, b, 1);         /// Set 1
        else if(ty=="E") ST.Update(a, b, 0);    /// Set 0
        else if(ty=="I") ST.Update(a, b, 2);    /// Flip
        else {
            int ret = ST.Query(a, b);
            cout << "Q" << qnum << ": " << ret << endl;
            qnum++;
        }
    }
}

int main () {
    #ifdef s_da_sailor
    freopen ( "input.txt", "r", stdin );
    freopen ( "output.txt", "w", stdout );
    #endif // s_da_sailor

    fast_cin;

    int tc;
    cin >> tc;

    for(ks=1; ks<=tc; ks++) {
        solve();
    }

    return 0;
}

