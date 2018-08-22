#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005
#define BIG 1000000000000005

long long dis[SIZE];
int pre[SIZE];

struct Node
{
    int id, dist;

    Node() {}

    Node(int id, int dist)
    {
        this->id = id;
        this->dist = dist;
    }

    bool operator < (const Node &a)const {
        return dist > a.dist;
    }
};

vector<pair<int, int> > G[SIZE];

void  dijkstra(int source)
{
    priority_queue<Node> Q;

    for(int i=0; i<SIZE; i++) {
        dis[i] = BIG;
        pre[i] = -1;
    }

    Node s(source, 0);

    Q.push(s);

    dis[source] = 0;

    //printf("BFS: %d", source);

    while(!Q.empty()) {
        Node curr = Q.top();
        Q.pop();

        int u = curr.id;
        int curr_dist = curr.dist;
        
        if(curr_dist!=dis[u]) continue;

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i].first;
            int cost = G[u][i].second;

            if(dis[u]+cost < dis[v]) {
                dis[v] = dis[u] + cost;

                Node n(v, dis[v]);

                Q.push(n);

                pre[v] = u;

                //printf(" %d", v);
            }
        }
    }
    //printf("\n");
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //fast_cin;

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        G[a].push_back(pair<int, int>(b, w));
        G[b].push_back(pair<int, int>(a, w));
    }

    dijkstra(1);

    if(dis[n]==BIG) {
        printf("-1\n");
    }
    else {
        vector<int> ansVec;

        int curr = n;
        while(curr!=1) {
            ansVec.push_back(curr);
            curr = pre[curr];
        }
        ansVec.push_back(1);

        for(int i=ansVec.size()-1; i>=0; i--) {
            if(i==ansVec.size()-1) printf("%d", ansVec[i]);
            else printf(" %d", ansVec[i]);
        }
        printf("\n");
    }

    return 0;
}
