class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) 
    {
        map<int,int>m;
        for(auto x:a)
        {
            for(auto y:x)
            {
                m[y]++;
            }
        }
        int in=1;
        int u1=1;
        for(auto x:m)
        {
            if(x.first==in)in++;
            if(x.second==2)u1=x.first;
        }
        return {u1,in};
        
    }
};
