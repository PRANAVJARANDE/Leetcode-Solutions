class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(char x: s)
        {
            m[x]++;
        }
        int ans=0;
        bool b=0;
        for(auto x: m)
        {
            if(x.second%2)b=1;
            ans+=x.second/2;
        }
        ans*=2;
        return ans+b;
    }
};
