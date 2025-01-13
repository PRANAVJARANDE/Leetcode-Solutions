class Solution {
public:
    int minimumLength(string s) {
        map<char,int>m;
        for(auto x:s)m[x]++;
        int ans=0;
        for(auto x:m)
        {
            int res=x.second%2;
            if(res==1)ans+=1;
            else ans+=2;
        }
        return ans;
    }
};
