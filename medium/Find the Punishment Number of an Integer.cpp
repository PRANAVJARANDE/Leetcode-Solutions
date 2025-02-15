class Solution {
public:

    bool check(int k,int cr)
    {
        string s=to_string(k);
        int sz=s.size();
        for(int i=0;i<(1<<sz);i++)
        {
            int cnt=0;
            int req=cr;
            for(int j=0;j<sz;j++)
            {
                int ch=s[j]-'0';
                if(i & (1<<j))
                {
                    req-=cnt;
                    cnt=0;
                }
                cnt*=10;
                cnt+=ch;
            }
            req-=cnt;
            if(req==0)return 1;
        }
        return 0;
    }

    int punishmentNumber(int n) {
        int ans=1;
        for(int i=2;i<=n;i++)
        {
            int sq=i*i;
            if(check(sq,i))
            {
                ans+=sq;
            }
        }
        return ans;
    }
};
