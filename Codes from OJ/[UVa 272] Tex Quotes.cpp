/// Verdict: AC

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    //freopen("in.txt", "rt", stdin);
    //freopen("out.txt", "wt", stdout);
    char str[100000], ch;
    long int count, len, i;

    count = 0;
    while(gets(str)) {
        len = strlen(str);
        for(i=0; i<len; i++) {
            if(str[i]=='"' && count%2==0) {
                printf("``");
                count++;
            }
            else if(str[i]=='"' && count%2==1) {
                printf("''");
                count++;
            }
            else {
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
