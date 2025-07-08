class FindSumPairs {
public:

    vector<int>nums1;
    vector<int>nums2;
    map<int,int>freq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        this->nums1=nums1;
        this->nums2=nums2;
        for(auto x:nums2)freq[x]++;
    }
    
    void add(int index, int val) 
    {
        freq[nums2[index]]--;
        nums2[index]+=val;
        freq[nums2[index]]++;
    }
    
    int count(int t) 
    {
        int ans=0;
        for(auto x:nums1)
        {
            ans+=freq[t-x];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
