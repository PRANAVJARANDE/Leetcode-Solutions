class Solution {
public:
    int prefixCount(vector<string>& words, string s) {
        int ans=0;
        int sz=s.size();
        for(auto x:words)
        {
            if(x.size()>=sz && x.substr(0,sz)==s)ans++;
        }
        return ans;
    }
};
