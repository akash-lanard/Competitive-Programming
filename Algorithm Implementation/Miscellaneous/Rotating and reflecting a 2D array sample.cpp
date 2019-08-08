/*
ID: akashla1
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    cin >> N;

    //input initAra
    int initAra[15][15];
    memset(initAra, 0, sizeof(initAra));

    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        for(int j=0; j<N; j++) {
            if(str[j]=='@') {
                initAra[i][j] = 1;
            }
        }
    }
    //input initAra end


    //input finalAra
    int finalAra[15][15];
    memset(finalAra, 0, sizeof(finalAra));

    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        for(int j=0; j<N; j++) {
            if(str[j]=='@') {
                finalAra[i][j] = 1;
            }
        }
    }
    //input finalAra end

    //mirror image
    int mirror[15][15];
    memset(mirror, 0, sizeof(mirror));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            mirror[i][j] = initAra[i][N-j-1];
        }
    }
    //mirror image end

    //rotate90
    int rotate90[15][15];
    memset(rotate90, 0, sizeof(rotate90));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            rotate90[i][j] = initAra[N-j-1][i];
        }
    }
    //rotate90 end

    //rotate180
    int tempAra1[15][15];
    memset(tempAra1, 0, sizeof(tempAra1));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tempAra1[i][j] = initAra[N-j-1][i];
        }
    }

    int rotate180[15][15];
    memset(rotate180, 0, sizeof(rotate180));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            rotate180[i][j] = tempAra1[N-j-1][i];
        }
    }
    //rotate180 end

    //rotate270
    memset(tempAra1, 0, sizeof(tempAra1));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tempAra1[i][j] = initAra[N-j-1][i];
        }
    }

    int tempAra2[15][15];
    memset(tempAra2, 0, sizeof(tempAra2));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tempAra2[i][j] = tempAra1[N-j-1][i];
        }
    }

    int rotate270[15][15];
    memset(rotate270, 0, sizeof(rotate270));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            rotate270[i][j] = tempAra2[N-j-1][i];
        }
    }
    //rotate270 end

    //rotate90mirror
    int rotate90mirror[15][15];
    memset(rotate90mirror, 0, sizeof(rotate90mirror));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            rotate90mirror[i][j] = mirror[N-j-1][i];
        }
    }
    //rotate90mirror end

    //rotate180mirror
    memset(tempAra1, 0, sizeof(tempAra1));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tempAra1[i][j] = mirror[N-j-1][i];
        }
    }

    int rotate180mirror[15][15];
    memset(rotate180mirror, 0, sizeof(rotate180mirror));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            rotate180mirror[i][j] = tempAra1[N-j-1][i];
        }
    }
    //rotate180mirror end

    //rotate270mirror
    memset(tempAra1, 0, sizeof(tempAra1));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tempAra1[i][j] = mirror[N-j-1][i];
        }
    }

    memset(tempAra2, 0, sizeof(tempAra2));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            tempAra2[i][j] = tempAra1[N-j-1][i];
        }
    }

    int rotate270mirror[15][15];
    memset(rotate270mirror, 0, sizeof(rotate270mirror));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            rotate270mirror[i][j] = tempAra2[N-j-1][i];
        }
    }
    //rotate270mirror end

    int flag = 0;


    //rotate90
    if(!flag) {
        flag = 1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(finalAra[i][j]!=rotate90[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) {
            cout << "1\n";
        }
    }
    //rotate90

    //rotate180
    if(!flag) {
        flag = 1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(finalAra[i][j]!=rotate180[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) {
            cout << "2\n";
        }
    }
    //rotate180

    //rotate270
    if(!flag) {
        flag = 1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(finalAra[i][j]!=rotate270[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) {
            cout << "3\n";
        }
    }
    //rotate270

    //Mirror
    if(!flag) {
        flag = 1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(finalAra[i][j]!=mirror[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) {
            cout << "4\n";
        }
    }
    //Mirror

    //rotate90mirror
    if(!flag) {
        flag = 1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(finalAra[i][j]!=rotate90mirror[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) {
            cout << "5\n";
        }
    }
    //rotate90mirror

    //rotate180mirror
    if(!flag) {
        flag = 1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(finalAra[i][j]!=rotate180mirror[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) {
            cout << "5\n";
        }
    }
    //rotate180mirror

    //rotate270mirror
    if(!flag) {
        flag = 1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(finalAra[i][j]!=rotate270mirror[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) {
            cout << "5\n";
        }
    }
    //rotate270mirror


    //No change
    if(!flag) {
        flag = 1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(finalAra[i][j]!=initAra[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) {
            cout << "6\n";
        }
    }
    //No change

    //invalid
    if(!flag) {
        cout << "7\n";
    }
    //invalid

    return 0;
}


