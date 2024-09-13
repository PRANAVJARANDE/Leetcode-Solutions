class Solution {
public:

    bool getbit(int i,int p)
    {
        return i & (1<<p);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        set<multiset<int>> s1;
        int n=nums.size();
        for(int i=0;i<pow(2,n);i++)
        {
            multiset<int> v1;
            for(int j=0;j<n;j++)
            {
                if(getbit(i,j))
                {
                    v1.insert(nums[j]);
                } 
            }
            s1.insert(v1);
        }

        vector<vector<int>> ans;
        for(auto x : s1)
        {
            vector<int> f;
            for(int y: x)
            {
                f.push_back(y);
            }
            ans.push_back(f);
        }

       


        return ans;
    }
};
