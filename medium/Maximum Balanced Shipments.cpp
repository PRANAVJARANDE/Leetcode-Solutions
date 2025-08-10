class Solution {
public:
    int maxBalancedShipments(vector<int>& a) 
    {
        int ans=0;
        int maxi=0;
        for(auto x:a)
        {
            if(maxi>x)
            {
                ans++;
                maxi=0;
            }
            else
            {
                maxi=max(maxi,x);
            }
        }
        return ans;
    }
};
