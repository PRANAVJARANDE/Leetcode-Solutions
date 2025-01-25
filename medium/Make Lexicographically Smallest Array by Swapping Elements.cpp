class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int l) 
    {
        int n=nums.size();
        vector<vector<int>>v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=nums[i];
            v1[i][1]=i;
        }
        sort(v1.begin(),v1.end());
        vector<int>ans(n,0);
        for(int i=0;i<n;)
        {
            vector<int>val;
            vector<int>in;
            int maxi=v1[i][0]+l;
            while(i<n && v1[i][0]<=maxi)
            {
                val.push_back(v1[i][0]);
                in.push_back(v1[i][1]);
                maxi=v1[i][0]+l;
                i++;
            }
            sort(val.begin(),val.end());
            sort(in.begin(),in.end());

            for(int z=0;z<in.size();z++)
            {
                ans[in[z]]=val[z];
            }
        }
        return ans;
    }
};
