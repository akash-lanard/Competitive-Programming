#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define SIZE 1005

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int cell[SIZE][SIZE];

int d[SIZE][SIZE], vis[SIZE][SIZE];

int row, col;

queue<pii> q;

void BFS2D(int sx, int sy) {
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;

    memset(d, 0, sizeof(d));

    while(!q.empty()) q.pop();
    q.push(pii(sx, sy));

    while(!q.empty()) {
        pii top = q.front();
        q.pop();
        for(int k=0; k<4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];
            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && vis[tx][ty]==0) {
                vis[tx][ty] = 1;
                d[tx][ty] = d[top.first][top.second] + 1;
                q.push(pii(tx, ty));
            }
        }
    }

}

void clr() {
    memset(cell, 0, sizeof(cell));
}

int main()
{
    row = 8;
    col = 8;

    clr();
    
    cell[0][1] = -1;
    cell[1][1] = -1;

    BFS2D(0, 0);

    cout << d[0][2] << endl;

    return 0;
}
