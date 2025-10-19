class Solution {
public:
    string findLexSmallestString(string s, int a, int b) 
    {   
        int n=s.size();
        queue<string>q1;
        q1.push(s);
        string ans=s;
        map<string,bool>vis;
        vis[s]=1;
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();

            string temp=in.substr(b)+in.substr(0,b);
            if(vis[temp]==0)
            {
                vis[temp]=1;
                ans=min(ans,temp);
                q1.push(temp);
            }

            for(int z=0;z<11;z++)
            {
                for(int g=1;g<n;g+=2)
                {
                    int val=in[g]-'0';
                    val+=a;
                    val=val%10;
                    in[g]=val+'0';
                }
                if(vis[in]==0)
                {
                    vis[in]=1;
                    ans=min(ans,in);
                    q1.push(in);
                }
            }
        }
        return ans;
    }
};
