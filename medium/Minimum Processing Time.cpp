class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& ta) {
        sort(pt.begin(),pt.end());
        sort(ta.begin(),ta.end(),greater<int>());
        
        int ans=INT_MIN;
        for(int i=0;i<pt.size();i++)
        {
                int z=INT_MIN;
                for(int j=0;j<4;j++)
                {
                        z=max(z,pt[i]+ta[4*i+j]);
                }
                ans=max(ans,z);
        }
            return ans;
    }
};
