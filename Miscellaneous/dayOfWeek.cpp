#include <bits/stdc++.h>
using namespace std;

int isleap(int y)
{
    return y%4==0 && (y%100 != 0 || y%400 == 0);
}

int dayOfWeek(int year, int month, int day)
{
    int init_y, init_m = 1, init_d = 1, init_DOW = 3, cnt=0;

    for(init_y=1 ; init_y<year; init_y++) {
        if(isleap(init_y)) cnt += 366;
        else cnt += 365;
    }
    for(init_m=1; init_m<month; init_m++) {
        if(init_m == 1 || init_m == 3 || init_m == 5 || init_m == 7 || init_m == 8 || init_m == 10 || init_m == 12) {
            cnt += 31;
        }
        else if(init_m == 4 || init_m == 6 || init_m == 9 || init_m == 11) {
            cnt += 30;
        }
        else if(init_m == 2 && isleap(year)==1) {
            cnt += 29;
        }
        else if(init_m == 2 && isleap(year)==0) {
            cnt += 28;
        }
    }
    for(init_d=1; init_d<day; init_d++) {
        cnt++;
    }
    long long ret = (cnt+3)%7;
    return ret;
}

int main()
{
    cout << dayOfWeek(2010, 8, 9) << endl;
    return 0;
}
