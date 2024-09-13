class Solution {
public:
    int numSpecial(vector<vector<int>>& arr) 
    {
        unordered_map<int,int> r,c;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j]==1)
                {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j]==1 && r[i]==1 && c[j]==1)
                {
                    ans++;
                }
            }
        }
        return ans;


        
    }
};
