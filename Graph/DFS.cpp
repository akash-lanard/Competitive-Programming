#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

int d[SIZE], f[SIZE], color[SIZE];
int ttime;

vector<int> lst;

vector<int> G[SIZE];

void DFS(int source)
{
    int u = source;
    ttime++;
    d[u] = ttime;
    color[u] = 1;

    for(int v = 0; v<G[u].size(); v++) {
        if(color[G[u][v]]==0) DFS(G[u][v]);
    }

    lst.push_back(u);

    color[u] = 2;
    ttime++;
    f[u] = ttime;

    return;
}

int main()
{
    G[1].push_back(4);
    G[2].push_back(1);
    G[2].push_back(3);
    G[3].push_back(4);

    //DFS(1);
    for(int i=1; i<SIZE; i++) {
        if(color[i]==0) DFS(i);
    }

    for(int i=1; i<SIZE; i++) {
        printf("Node: %d, d[]: %d, f[]: %d\n", i, d[i], f[i]);
    }

    for(int i=0; i<lst.size(); i++) {
        printf("%d ", lst[i]);
    }
    printf("\n");

    return 0;
}
