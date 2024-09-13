class Solution {
public:
    int minSteps(string s, string t) 
    {
        map<char,int> a,b;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            a[s[i]]++;
            b[t[i]]++;
        }    
        int ans=0;
        for(auto x: a)
        {
            char ch=x.first;
            if(a[ch]>b[ch])
            {
                ans+=a[ch]-b[ch];
            }
        }
        return ans;
    }
};
