class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<vector<int>> a;
        for(int i=0;i<nums.size();i++)
            for(auto y:nums[i])a.push_back({y,i});
        sort(a.begin(),a.end());

        int k=nums.size(),n=a.size();
        vector<int> ans;
        int maxi=INT_MAX;
        
        map<int,int> m;
        int l=0;
        int i=-1;
        while(i<n)
        {
            i++;
            if(i==n)break;
            m[a[i][1]]++;
            while(m.size()==k)
            {
                m[a[l][1]]--;
                if(m[a[l][1]]==0)m.erase(a[l][1]);
                if(m.size()<k)
                {
                    m[a[l][1]]++;
                    break;
                }
                l++;
            }
            if(m.size()==k)
            {
                int ndiff=a[i][0]-a[l][0];
                if(maxi>ndiff)
                {
                    maxi=ndiff;
                    ans={a[l][0],a[i][0]};
                }
            }
            
        }
        return ans;


    }
};
