class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& a) 
    {
        map<pair<int,int>,int>m;
        int ans=0;
        for(auto x:a)
        {
            int i1=x[0];
            int i2=x[1];
            if(i1>i2)swap(i1,i2);
            ans+=m[{i1,i2}];
            m[{i1,i2}]++;
        }
        return ans;
        
    }
};
