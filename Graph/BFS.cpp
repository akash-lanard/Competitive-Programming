#include <bits/stdc++.h>
using namespace std;

#define SIZE 1005
#define BIG 100000000

vector<int> G[SIZE];
int level[SIZE];

void BFS(int source)
{
    queue<int> Q;
    for(int i=0; i<SIZE; i++) level[i] = BIG;

    Q.push(source);
    level[source] = 0;

    while(Q.size()!=0) {
        int u = Q.front();
        Q.pop();

        for(int v = 0; v<G[u].size(); v++) {
            int curr = G[u][v];
            if(level[curr] == BIG) {
                level[curr] = level[u] + 1;
                Q.push(curr);
            }
        }
    }
    return;
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main()
{
    G[1].push_back(2);
    G[1].push_back(4);
    G[1].push_back(3);
    G[2].push_back(1);
    G[2].push_back(6);
    G[3].push_back(1);
    G[3].push_back(8);
    G[3].push_back(7);
    G[4].push_back(1);
    G[4].push_back(7);
    G[5].push_back(8);
    G[5].push_back(10);
    G[6].push_back(2);
    G[6].push_back(10);
    G[7].push_back(3);
    G[7].push_back(4);
    G[7].push_back(8);
    G[7].push_back(9);
    G[8].push_back(3);
    G[8].push_back(5);
    G[8].push_back(7);
    G[9].push_back(7);
    G[9].push_back(10);
    G[10].push_back(5);
    G[10].push_back(6);
    G[10].push_back(9);

    BFS(1);

    cout << level[5] << endl;

    return 0;
}
