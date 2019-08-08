#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

vector<pair<int, int> > G[SIZE];

int parent[SIZE];
int key[SIZE];
bool mstSet[SIZE];

int minKey()
{
    int mn = INT_MAX;
    int mn_indx;

    for(int i=0; i<SIZE; i++) {
        if(mstSet[i]==false && key[i]<mn) {
            mn = key[i];
            mn_indx = i;
        }
    }

    return mn_indx;
}

int printMST()
{
    printf("Edge    Weight\n");
    for(int i=1; i<SIZE; i++) {
        printf("%d - %d   ", parent[i], i);
        int cost = -1;
        for(int j=0; j<G[parent[i]].size(); j++) {
            if(G[parent[i]][j].first==i) {
                cost = G[parent[i]][j].second;
                break;
            }
        }
        printf("%d\n", cost);
    }
}

void primMST(int s)
{
    for(int i=0; i<SIZE; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[s] = 0;
    parent[s] = -1;

    for(int cnt=0; cnt<SIZE-1; cnt++) {
        int u = minKey();

        mstSet[u] = true;

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i].first;
            int cost = G[u][i].second;
            if(mstSet[v]==false && cost<key[v]) {
                parent[v] = u;
                key[v] = cost;
            }
        }
    }

    printMST();
}

int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
    G[0].push_back(pair<int,int>(1, 2));
    G[0].push_back(pair<int,int>(3, 6));
    G[1].push_back(pair<int,int>(0, 2));
    G[1].push_back(pair<int,int>(3, 8));
    G[1].push_back(pair<int,int>(4, 5));
    G[1].push_back(pair<int,int>(2, 3));
    G[2].push_back(pair<int,int>(1, 3));
    G[2].push_back(pair<int,int>(4, 7));
    G[3].push_back(pair<int,int>(0, 6));
    G[3].push_back(pair<int,int>(1, 8));
    G[3].push_back(pair<int,int>(4, 9));
    G[4].push_back(pair<int,int>(2, 7));
    G[4].push_back(pair<int,int>(1, 5));
    G[4].push_back(pair<int,int>(3, 9));

    // Print the solution
    primMST(0);

    return 0;
}
