class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int ans=0;
        int maxi=v[0];
        for(int i=1;i<v.size();i++)
        {
            ans=max(ans,maxi+v[i]-i);
            maxi=max(maxi,v[i]+i);
        }
        return ans;
    }
};
