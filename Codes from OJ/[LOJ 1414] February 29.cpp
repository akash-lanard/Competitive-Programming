/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, m1, m2, y1, y2, d1, d2, i, j, k, temp, cnt, x, y, z;
    char month[30];
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        scanf("%s %d, %d", month, &d1, &y1);
        if(!strcmp(month, "January")) m1 = 1;
        else if(!strcmp(month, "February")) m1 = 2;
        else if(!strcmp(month, "March")) m1 = 3;
        else if(!strcmp(month, "April")) m1 = 4;
        else if(!strcmp(month, "May")) m1 = 5;
        else if(!strcmp(month, "June")) m1 = 6;
        else if(!strcmp(month, "July")) m1 = 7;
        else if(!strcmp(month, "August")) m1 = 8;
        else if(!strcmp(month, "September")) m1 = 9;
        else if(!strcmp(month, "October")) m1 = 10;
        else if(!strcmp(month, "November")) m1 = 11;
        else if(!strcmp(month, "December")) m1 = 12;
 
        scanf("%s %d, %d", month, &d2, &y2);
 
        if(!strcmp(month, "January")) m2 = 1;
        else if(!strcmp(month, "February")) m2 = 2;
        else if(!strcmp(month, "March")) m2 = 3;
        else if(!strcmp(month, "April")) m2 = 4;
        else if(!strcmp(month, "May")) m2 = 5;
        else if(!strcmp(month, "June")) m2 = 6;
        else if(!strcmp(month, "July")) m2 = 7;
        else if(!strcmp(month, "August")) m2 = 8;
        else if(!strcmp(month, "September")) m2 = 9;
        else if(!strcmp(month, "October")) m2 = 10;
        else if(!strcmp(month, "November")) m2 = 11;
        else if(!strcmp(month, "December")) m2 = 12;
 
        if(y1>y2) {
            swap(y1, y2);
            swap(m1, m2);
            swap(d1, d2);
        }
        else if(y1==y2 && m1>m2) {
            swap(y1, y2);
            swap(m1, m2);
            swap(d1, d2);
        }
        else if(y1==y2 && m1==m2 && d1>d2) {
            swap(y1, y2);
            swap(m1, m2);
            swap(d1, d2);
        }
 
        if(m1>2) y1++;
        if(m2<2 || (m2==2 && d2<29)) y2--;
 
        x = y2/4 - (y1-1)/4;
        y = y2/100 - (y1-1)/100;
        z = y2/400 - (y1-1)/400;
        printf("Case %d: %d\n", i+1, x-y+z);
    }
 
    return 0;
}
