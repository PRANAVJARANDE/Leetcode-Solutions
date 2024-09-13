class Solution {
public:
    string getPermutation(int n, int k) 
    {
        vector<int>nums;
        int f=1;
        for(int i=1;i<n;i++)
        {
            f=f*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k--;
        string ans="";
        while(!nums.empty())
        {
            ans=ans+to_string(nums[k/f]);
            nums.erase(nums.begin()+k/f);
            if(nums.size()==0)
            {
                return ans;
            }
            k=k%f;
            f=f/(int)nums.size();
        }
        return ans;
    }
};
