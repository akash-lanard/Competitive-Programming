// Reference: https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
// This is a dynamic programming based solution. 
/*
Pseudo code:
1) Construct a sum matrix S[R][C] for the given M[R][C].
     a)    Copy first row and first columns as it is from M[][] to S[][]
     b)    For other entries, use following expressions to construct S[][]
         If M[i][j] is 1 then
            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
         Else If M[i][j] is 0
            S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print 
   sub-matrix of M[][]
*/

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
