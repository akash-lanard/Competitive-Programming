/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    double prevtime = 0;
    double curtime;
    int curhr, curmn, cursec, curspeed;
    int init=1;
    int prevhr=0, prevmn=0, prevsec=0, prevspeed=0;
    double curdis = 0.0;

    while(getline(cin, line)) {
        if(line.size()>8) {
            string s1 = line.substr(0, 2);
            string s2 = line.substr(3, 2);
            string s3 = line.substr(6, 2);
            string s4 = line.substr(9, line.size()-9);

            stringstream is1(s1);
            while(is1>>curhr) {

            }

            stringstream is2(s2);
            while(is2>>curmn) {

            }

            stringstream is3(s3);
            while(is3>>cursec) {

            }

            stringstream is4(s4);
            while(is4>>curspeed) {

            }

            if(init) {
                prevhr = curhr;
                prevmn = curmn;
                prevsec = cursec;
                prevspeed = curspeed;
                prevtime = curhr*3600 + curmn*60 + cursec;
                init = 0;
            }
            else {
                curtime = curhr*3600 + curmn*60 + cursec;
                if(curtime>=prevtime) {
                    double temp = (curtime - prevtime)/3600.0;
                    curdis += temp*prevspeed;
                }
                else if(curtime<prevtime) {
                    double temp = (24.0*3600.0) - prevtime + curtime;
                    curdis += temp*prevspeed;
                }

                prevhr = curhr;
                prevmn = curmn;
                prevsec = cursec;
                prevspeed = curspeed;
                prevtime = curtime;
            }
        }
        else if(line.size()==8) {
            string s1 = line.substr(0, 2);
            string s2 = line.substr(3, 2);
            string s3 = line.substr(6, 2);

            stringstream is1(s1);
            while(is1>>curhr) {

            }

            stringstream is2(s2);
            while(is2>>curmn) {

            }

            stringstream is3(s3);
            while(is3>>cursec) {

            }

            curtime = curhr*3600 + curmn*60 + cursec;
            if(curtime>=prevtime) {
                    double temp = (curtime - prevtime)/3600.0;
                    curdis += temp*prevspeed;
            }
            else if(curtime<prevtime) {
                double temp = (24.0*3600.0) - prevtime + curtime;
                curdis += temp*prevspeed;
            }
            cout << line;
            printf(" %0.2lf km\n", curdis);

            prevhr = curhr;
            prevmn = curmn;
            prevsec = cursec;
            prevspeed = curspeed;
            prevtime = curtime;
        }
    }
    return 0;
}
