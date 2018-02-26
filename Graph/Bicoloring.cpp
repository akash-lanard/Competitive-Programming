#include <bits/stdc++.h>
using namespace std;

#define SIZE 6

vector<int> G[SIZE+5];

bool Bicoloring(int source)
{
    queue<int> Q;
    Q.push(source);

    int color[SIZE+5];
    memset(color, 0, sizeof(color));
    color[source] = 1;

    while(Q.size()!=0) {
        int u = Q.front();
        Q.pop();

        for(int v=0; v<G[u].size(); v++) {
            if(color[G[u][v]]==0) {
                if(color[u]==1) color[G[u][v]] = 2;
                else color[G[u][v]] = 1;
                Q.push(G[u][v]);
            }

            if(color[u]==color[G[u][v]]) return false;
        }
    }

    return true;
}

int main()
{
    G[1].push_back(2);
    G[1].push_back(3);
    G[2].push_back(1);
    G[2].push_back(4);
    G[2].push_back(5);
    G[3].push_back(1);
    G[3].push_back(4);
    G[3].push_back(5);
    G[4].push_back(3);
    G[4].push_back(2);
    G[5].push_back(2);
    G[5].push_back(3);

    cout << Bicoloring(1) << endl;

    return 0;
}

