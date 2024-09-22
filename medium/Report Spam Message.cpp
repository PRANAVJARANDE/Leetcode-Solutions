class Solution {
public:
    bool reportSpam(vector<string>& a, vector<string>& b) {
        map<string,bool> m;
        for(auto x:b)m[x]=1;
        int cnt=0;
        for(auto x: a)
        {
            if(m[x])cnt++;
            if(cnt==2)return 1;
        }
        return 0;
    }
};
