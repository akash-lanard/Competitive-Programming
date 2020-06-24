   /// Verdict: AC
   
   #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int tc, i, j, k, len, flag;
        char str[20];
     
        scanf("%d", &tc);
        for(i=0; i<tc; i++) {
            scanf("%s", str);
            len = strlen(str);
            flag = 0;
     
            for(j=0, k=len-1; j<k; j++, k--) {
                if(str[j]!=str[k]) {
                    flag = 1;
                    break;
                }
            }
     
            if(!flag) printf("Case %d: Yes\n", i+1);
            else printf("Case %d: No\n", i+1);
        }
     
        return 0;
    }
     
