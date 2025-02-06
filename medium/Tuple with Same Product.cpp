class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                m[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto x:m)
        {
            int sz=x.second;
            int res=4*sz*(sz-1);
            ans+=res;
        }
        return ans;


    }
};
