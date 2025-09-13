class Solution {
public:
    int maxFreqSum(string s)
    {
        map<char,int>m;
        for(auto x:s)m[x]++;
        int m1=0,m2=0;
        for(auto x:m)
        {
            if(x.first=='a' || x.first=='e' || x.first=='i' || x.first=='o' || x.first=='u')m1=max(m1,x.second);
            else m2=max(m2,x.second);
        }
        return m1+m2;
    }
};
