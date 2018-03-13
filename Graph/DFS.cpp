#include <bits/stdc++.h>
using namespace std;

#define SIZE 50005

vector<int> G[SIZE];

//int visited[SIZE];

int d[SIZE], f[SIZE], color[SIZE];
int ttime;
vector<int> lst;

//int inDegree[SIZE];
//int cnt;
//int mark[SIZE];

void DFS(int source)
{
    int u = source;

    //visited[u] = 1;

    ttime++;
    d[u] = ttime;
    color[u] = 1;

    //cnt++;
    //mark[u] = 1;

    for(int v = 0; v<G[u].size(); v++) {
        int curr = G[u][v];
        if(color[curr]==0) {
            DFS(curr);
        }
        /*if(!visited[curr]) {
            DFS(curr);
        }*/
    }

    lst.push_back(u);
    color[u] = 2;
    ttime++;
    f[u] = ttime;

    return;
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();

    //memset(visited, 0, sizeof(visited));

    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));
    memset(color, 0, sizeof(color));
    lst.clear();
    ttime = 0;

    //memset(inDegree, 0, sizeof(inDegree));
    //memset(mark, 0, sizeof(mark));
}

int main()
{
    clr();

    int n = 5;

    G[1].push_back(4);
    G[2].push_back(1);
    G[2].push_back(3);
    G[3].push_back(4);

    //DFS(1);
    for(int i=1; i<n; i++) {
        if(color[i]==0) DFS(i);
    }

    for(int i=1; i<n; i++) {
        printf("Node: %d, d[]: %d, f[]: %d\n", i, d[i], f[i]);
    }

    for(int i=0; i<lst.size(); i++) {
        printf("%d ", lst[i]);
    }
    printf("\n");

    return 0;
}
