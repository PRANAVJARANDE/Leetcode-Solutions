class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<pair<int,pair<int,int>>> q1;
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int s=nums1[i]+nums2[j];
                
                if(q1.size()<k)
                {
                    q1.push({s,{nums1[i],nums2[j]}});
                }   
                else if(s<q1.top().first)
                {
                    q1.pop();
                    q1.push({s,{nums1[i],nums2[j]}});
                } 
                else
                {
                    break;
                }      
            }
        }
        vector<vector<int>> v1;
        while(!q1.empty())
        {
            v1.push_back({q1.top().second.first,q1.top().second.second});
            q1.pop();
        }
        return v1;
        
    }
};
