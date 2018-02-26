#include <bits/stdc++.h>
using namespace std;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int cell[100][100];

int d[100][100], vis[100][100];

int row, col;

void bfs(int sx, int sy)
{
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;

    queue<pair<int, int> > q;
    q.push(pair<int, int>(sx, sy));

    while(!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        for(int k=0; k<4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];
            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && vis[tx][ty]==0) {
                vis[tx][ty] = 1;
                d[tx][ty] = d[top.first][top.second] + 1;
                q.push(pair<int, int>(tx, ty));
            }
        }
    }

}

int main()
{
    row = 8;
    col = 8;

    memset(cell, 0, sizeof(cell));
    cell[0][1] = -1;
    cell[1][1] = -1;

    bfs(0, 0);

    cout << d[0][2] << endl;

    return 0;
}
