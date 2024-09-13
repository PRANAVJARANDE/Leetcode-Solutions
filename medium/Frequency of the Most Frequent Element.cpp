class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        long psum=0;
        long res=0;
        for(int i=0;i<n;i++)
        {
            psum+=nums[i];
            long wsize=i-l+1;

            while((nums[i]*wsize-psum)>k)
            {
                psum-=nums[l];
                l++;
                wsize--;
            }
            res=max(res,wsize);
        }
        return res;
    }
};
