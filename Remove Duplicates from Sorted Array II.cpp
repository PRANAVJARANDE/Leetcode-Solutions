class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        vector<int> arr;
        if(nums.size()<=2)
        {
            return nums.size();
        }
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]==nums[i+1] && nums[i]==nums[i+2])
            {
                continue;
            }
            arr.push_back(nums[i]);
        }
        arr.push_back(nums[nums.size()-2]);
        arr.push_back(nums[nums.size()-1]);
        
        for(int i=0;i<arr.size();i++)
        {
            nums[i]=arr[i];
        }

        return arr.size();


    }
};
