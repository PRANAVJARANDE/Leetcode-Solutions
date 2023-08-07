class Solution {
public:

    int maxRepeating(string s, string w) 
    {
        int ans=0;
        string temp=w;
        while(s.find(temp)!=string::npos)
        {
            temp+=w;
            ans++;
        }
        
        return ans;
        
    }
};
