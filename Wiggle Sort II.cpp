class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> a(n,0);
        int in=n-1;
        for(int i=1;i<n;i+=2)
        {
            a[i]=nums[in--];
        }
        for(int i=0;i<n;i+=2)
        {
            a[i]=nums[in--];
        }
        
        nums=a;
    }
};
