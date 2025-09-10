class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) 
    {
        for(auto &x:l) sort(x.begin(),x.end());
        int ans=INT_MAX;

        for(int i=1;i<=n;i++)
        {
            map<int,int> mp;
            for(auto &x:f)
            {
                int u=x[0]-1;
                int v=x[1]-1;

                bool can=false;
                for(auto lang:l[u])
                {
                    if(binary_search(l[v].begin(),l[v].end(),lang))
                    {
                        can=true;
                        break;
                    }
                }
                if(can)continue;
                if(!binary_search(l[u].begin(),l[u].end(),i)) mp[u]=1;
                if(!binary_search(l[v].begin(),l[v].end(),i)) mp[v]=1;
            }
            ans=min(ans,(int)mp.size());
        }
        return ans;
    }
};
