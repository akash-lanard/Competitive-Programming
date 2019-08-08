#include <bits/stdc++.h>
using namespace std;

#define SIZE 1005
#define BIG 1000000000000005

long long dis[SIZE];
int pre[SIZE];

int n;

vector<pair<int, int> > G[SIZE];

bool bellmanFord(int source)
{
    for(int i=0; i<SIZE; i++) {
        dis[i] = BIG;
        pre[i] = -1;
    }

    dis[source] = 0;

    for(int i=1; i<=n-1; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=0; k<G[j].size(); k++) {
                int currID = G[j][k].first;
                int currCost = G[j][k].second;

                if(dis[j] + currCost < dis[currID]) {
                    dis[currID] = dis[j] + currCost;

                    pre[currID] = j;
                }
            }
        }
    }

    for(int j=1; j<=n; j++) {
        for(int k=0; k<G[j].size(); k++) {
            int currID = G[j][k].first;
            int currCost = G[j][k].second;

            if(dis[j] + currCost < dis[currID]) {
                return false;
            }
        }
    }

    return true;
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main()
{
    #ifdef forthright48
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // forthright48

    clr();

    int m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back(pair<int, int>(v, w));
    }

    if(bellmanFord(1)) {
        for(int i=1; i<=n; i++) {
            if(dis[i]!=BIG) printf("dis[%d] = %lld\n", i, dis[i]);
            else printf("dis[%d] = inf\n", i);
        }

        for(int i=1; i<=n; i++) {
            printf("Path of %d:", i);
            if(dis[i]==BIG) {
                printf(" invalid\n");
            }
            else {
                vector<int> path;
                int curr = i;
                while(1) {
                    path.push_back(curr);
                    curr = pre[curr];
                    if(curr==-1) break;
                }

                for(int j=path.size()-1; j>=0; j--) {
                    printf(" %d", path[j]);
                }
                printf("\n");
            }
        }
    }
    else {
        printf("Negative cycle detected\n");
    }

    return 0;
}
