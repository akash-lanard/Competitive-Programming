#include <bits/stdc++.h>
using namespace std;

#define SIZE 1005
#define BIG 100000000

vector<int> G[SIZE];    /// Graph
int level[SIZE];        /// level of the nodes (distance, as the graph is unweighted)

queue<int> Q;
void BFS(int source) {
    while(!Q.empty()) Q.pop();

    for(int i=0; i<SIZE; i++) level[i] = BIG; /// initially the distance is inf (it is also used as visited)

    Q.push(source);     /// push source node in queue
    level[source] = 0;  /// level of source node is 0

    while(!Q.empty()) {
        int curr = Q.front();   /// curr node in the front of the queue, pop it
        Q.pop();

        for(int i = 0; i<G[curr].size(); i++) {
            int next = G[curr][i];
            if(level[next] == BIG) {    /// if next node is not updated update it
                level[next] = level[curr] + 1;  /// update level of next node
                Q.push(next);                   /// push next in the queue
            }
        }
    }
    return;
}

void clr() {
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main() {
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
