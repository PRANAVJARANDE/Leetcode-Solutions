class Solution {
public:

    int numTilePossibilities(string s) 
    {
        int n=s.size();
        map<string,int>vis;
        int ans=0;
        for(int i=1;i<(1<<n);i++)
        {
            string r="";
            map<char,int>freq;
            int cnt=1;
            int in=1;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                {
                    r+=s[j];
                    cnt*=in;
                    freq[s[j]]++;
                    cnt/=freq[s[j]];
                    in++;
                }
            }
            sort(r.begin(),r.end());
            if(vis[r]==0)
            {
                vis[r]=1;
                ans+=cnt;
            }
        }
        return ans;


    }
};
