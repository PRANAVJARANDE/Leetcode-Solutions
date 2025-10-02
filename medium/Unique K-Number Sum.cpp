class Solution {
  public:
    vector<vector<int>> combinationSum(int n, int k)
    {
        vector<vector<int>>ans;
        for(int i=0;i<(1<<9);i++)
        {
            int cnt=0,s=0;
            for(int j=0;j<9;j++)
            {
                if(i & (1<<j))
                {
                    cnt++;
                    s+=j+1;
                }
            }
            if(s==n && cnt==k)
            {
                vector<int>res;
                for(int j=0;j<9;j++)
                {
                    if(i & (1<<j))
                    {
                        res.push_back(j+1);
                    }
                }
                ans.push_back(res);
            }
        }
        return ans;
        
    }
};
