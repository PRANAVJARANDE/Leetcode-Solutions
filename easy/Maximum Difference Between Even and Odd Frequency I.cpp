class Solution {
public:
    int maxDifference(string s) {
        map<int,int>m;
        for(auto x:s)m[x]++;
        int ans=INT_MIN;
        for(auto x:m)
        {
            for(auto y:m)
            {
                if(x.second%2 != y.second%2)
                {
                    if(x.second%2==1)ans=max(ans,x.second-y.second);
                    else ans=max(ans,y.second-x.second);
                }
            }
        }
        if(ans==INT_MIN)ans=0;
        return ans;
    }
};
