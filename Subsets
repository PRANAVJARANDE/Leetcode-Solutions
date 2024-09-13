class Solution {
public:

    bool getbit(int n,int p)
    {
        return (n & 1<<p);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> v1;
        for(int i=0;i<pow(2,nums.size());i++)
        {
            vector<int> v2;
            for(int j=0;j<nums.size();j++)
            {
                
                if(getbit(i,j))
                {
                    v2.push_back(nums[j]);
                }


            }

            v1.push_back(v2);

        }
return v1;



    }
};
