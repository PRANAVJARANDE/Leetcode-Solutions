class Solution {
public:
    bool wordBreak(string s, vector<string>& arr) 
    {
        int n=s.size();
        vector<bool> vis(s.size()+1,0);
        vis[0]=1;

        for(int i=0;i<n;i++)
        {
                for(int j=0;j<arr.size();j++)
                {
                    if(vis[i]==1)
                    {
                        if(s.substr(i,arr[j].size()).compare(arr[j])==0)
                        {
                            vis[i+arr[j].size()]=1;
                        }
                    }
                }
        } 
        return vis[s.size()];
    }
};
