#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 2e3 + 5;

/**
code courtesy : Rajan Bardhan
we know the text & pattern matrix beforehand
calculates value of pattern first
then calculates hash_matrix for text keeping in mind the pattern SIZE
Hash_Matrix[i][j] constains the Hash value for the submatrix
starting at i , j & lenght of pattern size
*/

const int MOD[] = { 1000000007 , 1000000009 };
const int Base[] = { 37 , 43 };

int textRow , textCol , patRow , patCol ; /// row , col of text & pattern respectively
char text[ MAXN ][ MAXN ] , pattern[ MAXN ][ MAXN ];
LL Hash_Matrix[ MAXN ][ MAXN ];


LL Pattern_Hash( ) { /// calculates hash value of the pattern matrix..
        for( int i = 0; i < patRow; i++ ) {
                LL P = 0;
                for( int j = 0; j < patCol; j++ ) {
                        P = ( P * Base[0] + pattern[i][j] ) % MOD[0] ;
                }
                Hash_Matrix[i][0] = P;
        }
        for( int j = 0; j < patCol; j++ ) {
                LL P = 0;
                for( int i = 0; i < patRow; i++ ) {
                        P = ( P * Base[1] + Hash_Matrix[i][j] ) % MOD[1] ;
                }
                Hash_Matrix[0][j] = P ;
        }
        return Hash_Matrix[0][0] ;
}
void Text_Hash( ) { /// calculates hash_matrix of the Text matrix..
        LL d = 1;
        for( int i = 1; i < patCol; i++ ) d = ( d * Base[0] ) % MOD[0];
        for( int i = 0; i < textRow; i++ ) {
                LL P = 0 ;
                for( int j = 0; j < patCol; j++ ) {
                        P = ( P * Base[0] + text[i][j] ) % MOD[0];
                }
                for( int j = 0; j <= textCol - patCol; j++ ) {
                        Hash_Matrix[i][j] = P ;
                        P = ( ( ( P - text[i][j] * d ) % MOD[0] ) * Base[0] + text[i][j+patCol] )%MOD[0];
                        P = ( P + MOD[0] )%MOD[0];
                }
        }
        d = 1 ;
        for( int i = 1; i < patRow; i++ ) d = ( d * Base[1] ) % MOD[1];
        for( int j = 0; j <= textCol - patCol; j++ ) {
                LL P = 0 ;
                for( int i = 0; i < patRow; i++ ) {
                        P = ( P * Base[1] + Hash_Matrix[i][j] ) % MOD[1] ;
                }
                for( int i = 0; i <= textRow - patRow; i++ ) {
                        LL temp = P ;
                        P = ( ( ( P - Hash_Matrix[i][j] * d )%MOD[1])*Base[1] + Hash_Matrix[i+patRow][j] )%MOD[1];
                        P = ( P + MOD[1] ) % MOD[1];
                        Hash_Matrix[i][j] = temp ;
                }
        }
}
int main( int argc , char const *argv[] ) {
        //freopen( "input.txt" , "r" , stdin );
        //freopen( "output.txt" , "w" , stdout );
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d %d",&textRow,&textCol); /// text size
                for( int i = 0; i < textRow; i++ ) scanf("%s",text[i]);
                scanf("%d %d",&patRow,&patCol);
                for( int i = 0; i < patRow; i++ ) scanf("%s",pattern[i]);
                LL Hash = Pattern_Hash( );
                Text_Hash( );
                int ans = 0;
                for( int i = 0; i <= textRow - patRow; i++ ) {
                        for( int j = 0; j <= textCol - patCol; j++ ) {
                                if( Hash_Matrix[i][j] == Hash ) ans++;
                        }
                }
                printf("%d\n",ans);
        }
        return 0;
}
