class Solution {
public:
    int reverseDegree(string s) 
    {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int ta=s[i]-'a';
            int a=(26-ta)*(i+1);
            ans+=a;
        }
        return ans;
        
    }
};
