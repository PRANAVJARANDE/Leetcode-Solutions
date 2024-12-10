class Solution {
public:
    int maximumLength(string s) 
    {
        int ans=-1;
        for(char c='a';c<='z';c++)
        {
            map<int,int> m;
            int cnt=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]==c)
                {
                    cnt++;
                }
                else
                {
                    if(cnt>0)m[cnt]++;
                    if(cnt-1>0)m[cnt-1]+=2;
                    if(cnt-2>0)m[cnt-2]+=3;
                    cnt=0;
                }
            }
            if(cnt>0)m[cnt]++;
            if(cnt-1>0)m[cnt-1]+=2;
            if(cnt-2>0)m[cnt-2]+=3;

            for(auto x: m)
            {
                if(x.second>=3)ans=max(ans,x.first);
            }

        }
        return ans;
    }
};
