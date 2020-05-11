#define SIZE 1005

int row, col;
int mat[SIZE][SIZE], U[SIZE][SIZE], D[SIZE][SIZE], L[SIZE][SIZE], R[SIZE][SIZE];

pii parent[SIZE][SIZE];
int sz[SIZE][SIZE];

void makeset(int i, int j) {
    parent[i][j] = pii(i, j);
    sz[i][j] = 1;
}

void init_disjoint_set() {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
           if(mat[i][j]==1) makeset(i, j);
        }
    }
}

pii FindRepresentative(int r, int c) {  //with path compression
    if(parent[r][c]==pii(r, c)) {
        return parent[r][c];
    }

    parent[r][c] = FindRepresentative(parent[r][c].ff, parent[r][c].ss);

    return parent[r][c];
}

int FindSize(int r, int c) {
    pii rep = FindRepresentative(r, c);
    return sz[rep.ff][rep.ss];
}

void Union(int x1, int y1, int x2, int y2) {
    pii u = FindRepresentative(x1, y1);
    pii v = FindRepresentative(x2, y2);

    if(u!=v) {
        if(sz[v.ff][v.ss]>=sz[u.ff][u.ss]) {
            parent[u.ff][u.ss] = v;
            sz[v.ff][v.ss] += sz[u.ff][u.ss];
        }
        else {
            parent[v.ff][v.ss] = u;
            sz[u.ff][u.ss] += sz[v.ff][v.ss];
        }
    }
}
