class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
        {
            if(k%2==0)
            {
                return nums[0];
            }
            return -1;
        }
        priority_queue<int>q1;
        int a1=-1,a2=-1;
        for(int i=0;i<min(k-1,n);i++)
        {
            a1=max(a1,nums[i]);
        }
        if(k<n)
        {
            a2=nums[k];
        }
        return max(a1,a2);
    }
};
