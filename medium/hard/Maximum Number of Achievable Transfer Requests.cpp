class Solution {
public:

    bool  getbit(int n,int p)
    {
        return n & 1<<p;
    }


    int maximumRequests(int n, vector<vector<int>>& req) 
    {
        int ans=0;
        for(int i=0;i<(1<<req.size());i++)
        {
            vector<int> temp(n,0);
            int t=0;
            for(int j=0;j<req.size();j++)
            {
                if(i & (1<<j))
                {
                    t++;
                    temp[req[j][0]]--;
                    temp[req[j][1]]++;
                }
            }
            bool b=1;
            for(int j=0;j<n;j++)
            {
                if(temp[j]!=0)
                {
                    b=0;
                    break;
                }
            }
    
            if(b)
            {
                ans=max(ans,t);
            }
            
        }
        return ans;
    }
};
