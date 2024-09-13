class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) 
    {
            int n=nums.size();
            vector<int> maxi(n),mini(n);
            maxi[n-1]=n-1;
            mini[n-1]=n-1;
            
            for(int i=n-2;i>=0;i--)
            {
                    if(nums[i]>nums[maxi[i+1]])
                    {
                            maxi[i]=i;
                    }
                    else
                    {
                            maxi[i]=maxi[i+1];
                    }
                    
                    if(nums[i]<nums[mini[i+1]])
                    {
                            mini[i]=i;
                    }
                    else
                    {
                            mini[i]=mini[i+1];
                    }
                    
            }
            for(int i=0;i<n-id;i++)
            {
                    int mi=nums[mini[i+id]];
                    int ma=nums[maxi[i+id]];
                    
                    if(abs(nums[i]-mi)>=vd)
                    {
                            return {i,mini[i+id]};
                    }
                    if(abs(nums[i]-ma)>=vd)
                    {
                            return {i,maxi[i+id]};
                    }
                    
            }
            return {-1,-1};
        
    }
};
