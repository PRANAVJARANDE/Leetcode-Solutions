class Solution {
public:
        
        int helper(vector<int>&arr,int k)
        {
               int s=0,l=0,ans=1;
                for(int i=0;i<arr.size();i++)
                {
                        s+=arr[i];
                        while(s>k)
                        {
                                s-=arr[l];
                                l++;
                        }
                        ans=max(ans,i-l+2);
                }
                return ans;
        }
        
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
            unordered_map<int,vector<int>>m;
            int n=nums.size();
            if(n==1)
            {
                    return 1;
            }
            if(n==2)
            {
                    if(nums[0]==nums[1])
                    {
                            return 2;
                    }
                    return 1;
            }
            for(int i=0;i<n;i++)
            {
                    m[nums[i]].push_back(i);
            }
            int ans=1;
            for(auto x: m)
            {
                    vector<int>temp;
                    for(int i=1;i<x.second.size();i++)
                    {
                           temp.push_back(x.second[i]-x.second[i-1]-1); 
                    }
                   ans=max(ans,helper(temp,k)); 
            }
            return ans;
        
    }
};
