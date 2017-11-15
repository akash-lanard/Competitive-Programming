#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    cin.ignore();

    char ara[n+5][n+5];

    for(int i=1; i<=n; i++) {       //input given array
        for(int j=1; j<=n; j++) {
            scanf("%c", &ara[i][j]);
        }
        cin.ignore();
    }

    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%c", ara[i][j]);
        }
        printf("\n");
    }*/

    char fig1[n+5][n+5];
    for(int i=1, indx1 = 1; i<=n && indx1<=n; i++, indx1++) { //rotate 90deg
        for(int j=1, indx2 = n; j<=n && indx2>=1; j++, indx2--) {
            fig1[i][j] = ara[indx2][indx1];
        }
    }

    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%c", fig1[i][j]);
        }
        printf("\n");
    }*/

    char fig2[n+5][n+5];
    for(int i=1, indx1 = 1; i<=n && indx1<=n; i++, indx1++) { //rotate 180 dig
        for(int j=1, indx2 = n; j<=n && indx2>=1; j++, indx2--) { //by rotating
            fig2[i][j] = fig1[indx2][indx1];                  //fig1 again
        }
    }

    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%c", fig2[i][j]);
        }
        printf("\n");
    }*/

    char fig3[n+5][n+5];        //rotate 270 dig
    for(int i=1, indx1 = 1; i<=n && indx1<=n; i++, indx1++) {
        for(int j=1, indx2 = n; j<=n && indx2>=1; j++, indx2--) {
            fig3[i][j] = fig2[indx2][indx1];
        }
    }

    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%c", fig3[i][j]);
        }
        printf("\n");
    }*/

    char fig4[n+5][n+5];       //reflecting(mirror image)
    for(int i=1, indx1=1; i<=n && indx1<=n; i++, indx1++) {
        for(int j=1, indx2=n; j<=n && indx2>=1; j++, indx2--) {
            fig4[i][j] = ara[indx1][indx2];
        }
    }

    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%c", fig4[i][j]);
        }
        printf("\n");
    }*/

    char fig5_1[n+5][n+5];      //reflacting + rotating 90deg
    for(int i=1, indx1 = 1; i<=n && indx1<=n; i++, indx1++) {
        for(int j=1, indx2 = n; j<=n && indx2>=1; j++, indx2--) {
            fig5_1[i][j] = fig4[indx2][indx1];
        }
    }

    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%c", fig5_1[i][j]);
        }
        printf("\n");
    }*/

    char fig5_2[n+5][n+5];      //reflacting + rotating 180deg
    for(int i=1, indx1 = 1; i<=n && indx1<=n; i++, indx1++) {
        for(int j=1, indx2 = n; j<=n && indx2>=1; j++, indx2--) {
            fig5_2[i][j] = fig5_1[indx2][indx1];
        }
    }

    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%c", fig5_2[i][j]);
        }
        printf("\n");
    }*/


    char fig5_3[n+5][n+5];      //reflacting + rotating 270deg
    for(int i=1, indx1 = 1; i<=n && indx1<=n; i++, indx1++) {
        for(int j=1, indx2 = n; j<=n && indx2>=1; j++, indx2--) {
            fig5_3[i][j] = fig5_2[indx2][indx1];
        }
    }

    /*for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%c", fig5_3[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}

