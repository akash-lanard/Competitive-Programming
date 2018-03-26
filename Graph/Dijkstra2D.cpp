#include <bits/stdc++.h>
using namespace std;

#define SIZE 1005

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int ara[SIZE][SIZE];

int d[SIZE][SIZE];

int cell[SIZE][SIZE];

int row, col;

struct Node
{
    int id_x, id_y, dist;

    Node() {}

    Node(int id_x, int id_y, int dist)
    {
        this->id_x = id_x;
        this->id_y = id_y;
        this->dist = dist;
    }

    bool operator < (const Node &a)const {
        return dist > a.dist;
    }
};

void  dijkstra2D(int sx, int sy)
{
    priority_queue<Node> Q;

    d[sx][sy] = ara[sx][sy];

    Node s(sx, sy, d[sx][sy]);

    Q.push(s);

    //printf("BFS: %d", source);

    while(!Q.empty()) {
        Node curr = Q.top();
        Q.pop();

        int curr_x = curr.id_x;
        int curr_y = curr.id_y;
        int curr_dist = curr.dist;

        if(curr_dist != d[curr_x][curr_y]) continue;

        for(int k=0; k<4; k++) {
            int tx = curr_x + fx[k];
            int ty = curr_y + fy[k];

            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1) {
                int cost = ara[tx][ty];

                if(curr_dist + cost < d[tx][ty]) {
                    d[tx][ty] = curr_dist + cost;

                    Node n(tx, ty, d[tx][ty]);
                    Q.push(n);
                }
            }
        }
    }
    //printf("\n");
}

void clr()
{
    memset(ara, 1, sizeof(ara));

    memset(cell, 0, sizeof(cell));

    memset(d, 1, sizeof(d));
}

int main () {
    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //fast_cin;

    clr();

    scanf("%d %d", &row, &col);
    for(int j=0; j<row; j++) {
        for(int k=0; k<col; k++) {
            scanf("%d", &ara[j][k]);
        }
    }

    dijkstra2D(0, 0);

    printf("d contains:\n");
    for(int j=0; j<row; j++) {
        for(int k=0; k<col; k++) {
            printf("%d ", d[j][k]);
        }
        printf("\n");
    }

    return 0;
}
