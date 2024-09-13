class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int>v1(250,-1);
        int lmax=0,sp=-1;
        for(int i=0;i<s.length();i++)
        {
            if(v1[s[i]]!=-1)
            {
                sp=max(sp,v1[s[i]]);
            }
            v1[s[i]]=i;
            lmax=max(lmax,i-sp);
           
        }
        return lmax;
    }
};
