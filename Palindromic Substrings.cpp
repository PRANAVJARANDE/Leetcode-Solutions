class Solution {
public:
    int countSubstrings(string s) 
    {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int l=i,j=i;
            while(l>=0 && j<n && s[l]==s[j])
            {
                ans++;
                l--;
                j++;
            }

            if(i+1<n && s[i]==s[i+1])
            {
                l=i,j=i+1;
                while(l>=0 && j<n && s[l]==s[j])
                {
                    ans++;
                    l--;
                    j++;
                }
            }
        }
        return ans;
        
    }
};
