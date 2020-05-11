#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

vector<int> G[SIZE];
int color[SIZE];
int color1cnt, color2cnt;
queue<int> Q;

bool Bicoloring(int source) {
    while(!Q.empty()) Q.pop();
    Q.push(source);

    memset(color, 0, sizeof(color));
    color1cnt = 0;
    color2cnt = 0;

    color[source] = 1;
    color1cnt++;

    while(Q.size()!=0) {
        int u = Q.front();
        Q.pop();

        for(int v=0; v<G[u].size(); v++) {
            int curr = G[u][v];
            if(color[curr]==0) {
                if(color[u]==1) {
                    color[curr] = 2;
                    color2cnt++;
                }
                else {
                    color[curr] = 1;
                    color1cnt++;
                }
                Q.push(curr);
            }

            if(color[u]==color[curr]) return false;
        }
    }

    return true;
}

void clr() {
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main()
{
    clr();
    
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

