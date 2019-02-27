//https://codeforces.com/contest/1131/problem/F

#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

#define SIZE 150005

vector<int> Vec[SIZE];

int parent[SIZE];
int sz[SIZE];
int indx[SIZE];

void makeset(int u) {
    parent[u] = u;
    sz[u] = 1;
    indx[u] = u;
}

void init_disjoint_set(int N) {
    for(int i=0; i<=N; i++) {
        makeset(i);
        Vec[i].push_back(i);
    }
}

int FindRepresentative(int r) {  //with path compression
    if(parent[r]==r) {
        return r;
    }

    parent[r] = FindRepresentative(parent[r]);

    return parent[r];
}

int FindSize(int r) {
    return sz[FindRepresentative(r)];
}

void Union(int a, int b) {
    int u = FindRepresentative(a);
    int v = FindRepresentative(b);


    if(u!=v && sz[v]<=sz[u]) {
        parent[v] = u;
        sz[u] += sz[v];

        while(!Vec[indx[v]].empty()) {
            Vec[indx[u]].push_back(Vec[indx[v]].back());
            Vec[indx[v]].pop_back();
        }
    }
    else if(u!=v && sz[v]>sz[u]) {
        parent[u] = v;
        sz[v] += sz[u];

        while(!Vec[indx[u]].empty()) {
            Vec[indx[v]].push_back(Vec[indx[u]].back());
            Vec[indx[u]].pop_back();
        }
    }
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    int n;
    cin >> n;

    init_disjoint_set(n);

    for(int i=1; i<=n-1; i++) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int ind = indx[FindRepresentative(1)];

    for(int i=0; i<Vec[ind].size(); i++) {
        if(i!=0) cout << " ";
        cout << Vec[ind][i];
    }
    cout << "\n";

    return 0;
}

