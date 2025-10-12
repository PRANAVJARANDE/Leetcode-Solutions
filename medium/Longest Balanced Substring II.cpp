class Solution {
public:
    int longestBalanced(string s) 
    {
        int n=s.size();
        int ans=1;
        map<array<int,3>,int>m,mab,mac,mbc;
        m[{0,0,0}]=-1;
        mab[{0,0}]=-1;
        mac[{0,0}]=-1;
        mbc[{0,0}]=-1;

        int as=0,bs=0,cs=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')as++;
            else if(s[i]=='b')bs++;
            else cs++;
            int mini=min(as,min(bs,cs));
            if(m.find({as-mini,bs-mini,cs-mini})!=m.end())ans=max(ans,(i-m[{as-mini,bs-mini,cs-mini}]));
            else m[{as-mini,bs-mini,cs-mini}]=i;
        }

        // ab
        as=0,bs=0,cs=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='c')
            {
                as=0;
                bs=0;
                mab.clear();
                mab[{0,0}]=i;
                continue;
            }
            else if(s[i]=='a')as++;
            else bs++;
            int mini1=min(as,bs);
            if(mab.find({as-mini1,bs-mini1})!=mab.end())ans=max(ans,(i-mab[{as-mini1,bs-mini1}]));
            else mab[{as-mini1,bs-mini1}]=i;
        }

        // ac
        as=0,bs=0,cs=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b')
            {
                as=0;
                cs=0;
                mac.clear();
                mac[{0,0}]=i;
                continue;
            }
            else if(s[i]=='a')as++;
            else cs++;
            int mini2=min(as,cs);
            if(mac.find({as-mini2,cs-mini2})!=mac.end())ans=max(ans,(i-mac[{as-mini2,cs-mini2}]));
            else mac[{as-mini2,cs-mini2}]=i;
        }

        // bc
        as=0,bs=0,cs=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                cs=0;
                bs=0;
                mbc.clear();
                mbc[{0,0}]=i;
                continue;
            }
            else if(s[i]=='b')bs++;
            else cs++;
            int mini3=min(bs,cs);
            if(mbc.find({bs-mini3,cs-mini3})!=mbc.end())ans=max(ans,(i-mbc[{bs-mini3,cs-mini3}]));
            else mbc[{bs-mini3,cs-mini3}]=i;
        }


        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])cnt++;
            else cnt=1;
            ans=max(ans,cnt);
        }
        return ans;
    }
};
