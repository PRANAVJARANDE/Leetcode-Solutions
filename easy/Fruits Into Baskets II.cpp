class Solution {
public:
    int numOfUnplacedFruits(vector<int>& a, vector<int>& b) 
    {
        int ans=0;
        int n=a.size();
        vector<int>vis(n,0);
        for(int x:a)
        {
            bool bx=0;
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0 && b[i]>=x)
                {
                    vis[i]=1;
                    bx=1;
                    break;
                }
            }
            if(bx==0)ans++;
        }
        return ans;
    }
};
