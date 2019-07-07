#define SIZE 505

int n, m;
int A[SIZE][SIZE], S[SIZE][SIZE];

int calcMax() {
    memset(S, 0, sizeof(S));

    for(int i=1; i<=n; i++) {
        S[i][1] = A[i][1];
    }
    for(int i=1; i<=m; i++) {
        S[1][i] = A[1][i];
    }

    for(int i=2; i<=n; i++) {
        for(int j=2; j<=m; j++) {
            if(A[i][j]==1) {
                S[i][j] = min(S[i-1][j-1], min(S[i-1][j], S[i][j-1])) + 1;
            }
            else {
                S[i][j] = 0;
            }
        }
    }

    int mx = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            mx = max(mx, S[i][j]);
        }
    }

    return mx;
}
