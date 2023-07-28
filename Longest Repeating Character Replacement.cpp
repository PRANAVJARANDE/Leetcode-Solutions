class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n=s.size(),ans=0,j=0,ma=INT_MIN;
        unordered_map<char,int> m;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
            ma=max(ma,m[s[i]]);
            if(i-j+1-ma>k)
            {
                m[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
}
