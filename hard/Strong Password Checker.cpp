class Solution {
public:
    
    int strongPasswordChecker(string a) {
        int n=a.size();
        int uc=1,lc=1,dig=1;
        for(auto x: a)
        {
            if('0'<=x && x<='9')dig=0;
            else if('a'<=x && x<='z')lc=0;
            else if('A'<=x && x<='Z')uc=0;
        }
        int req=uc+lc+dig;
        int sum=0;
        int tc=0,oc=0,zc=0;
        for(int i=2;i<n;i++)
        {
            if(a[i]==a[i-1] && a[i]==a[i-2])
            {
                int cnt=2;
                while(i<n && a[i]==a[i-1] && a[i]==a[i-2])
                {
                    i++;
                    cnt++;
                }
                sum+=(cnt/3);
                if(cnt%3==1)oc++;
                else if(cnt%3==2)tc++;
                else zc++;
                i--;
            }
        }
        
        if(n<6)
        {
            int ins=6-n;
            return max(ins,req);
        }   
        else if(n<=20)
        {
            return max(req,sum);
        }
        else 
        {
            int del=n-20;
            sum-=min(del,zc);
            sum-=min(max(del-zc,0),oc*2)/2;
            sum-=min(max(del-zc-2*oc,0),sum*3)/3;
            return del+max(sum,req);
        }
    }
};
