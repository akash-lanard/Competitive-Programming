/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff first
#define ss second
#define LL long long
typedef pair < int, int > pii;
const LL inf = 2147383647;

#define SIZE 205

int ks;
LL buzzy[SIZE];
LL N, M, dis[SIZE], cost_uv[200005];
vector<pii> edgeVec;

void bellmanFord(int src) {
    for(int i=0; i<N; i++) {
        dis[i] = inf;
    }

    dis[0] = 0;
    for(int i=0; i<N-1; i++) {
        bool upd = false;
        for(int j=0; j<M; j++) {
            int u = edgeVec[j].ff, v = edgeVec[j].ss;
            if(dis[u]!=inf && dis[u]+cost_uv[j]<dis[v]) {
                dis[v] = dis[u] + cost_uv[j];
                upd = true;
            }
        }
        if(!upd) break;
    }

    for(int i=0; i<M; i++) {
        int u = edgeVec[i].ff, v = edgeVec[i].ss;
        if(dis[u]!=inf && dis[u]+cost_uv[i]<dis[v]) {
            dis[v] = -inf;
        }
    }
}

void solve() {
    for(int i=0; i<N; i++) {
        cin >> buzzy[i];
    }
    cin >> M;
    edgeVec.clear();
    for(int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        edgeVec.push_back(make_pair(u, v));
        cost_uv[i] = ((buzzy[v]-buzzy[u])*(buzzy[v]-buzzy[u])*(buzzy[v]-buzzy[u]));
    }

    bellmanFord(0);

    cout << "Set #" << ks << "\n";
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int x;
        cin >> x; x--;
        if(dis[x]<3 || dis[x]==inf) {
            cout << "?\n";
        }
        else {
            cout << dis[x] << "\n";
        }
    }
}

int main () {
    fast_cin;

    ks = 1;
    while(cin >> N) {
        solve();
        ks++;
    }

    return 0;
}
