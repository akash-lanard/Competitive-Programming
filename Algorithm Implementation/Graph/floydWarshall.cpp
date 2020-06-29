#define SIZE 105

int G[SIZE][SIZE];

void floydWarshall() {
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(G[i][j]>G[i][k]+G[k][j]) {
                    G[i][j] = G[i][k]+G[k][j];
                }
            }
        }
    }
}
