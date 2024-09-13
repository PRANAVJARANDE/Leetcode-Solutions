class Solution {
public:

    string longestPalindrome(string s) 
    {
        int n=s.size();
        string ans="";

        for(int i=0;i<n;i++)
        {
            int l=i-1,r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
            string temp=s.substr(l+1,r-l-1);
            if(ans.size()<temp.size())
            {
                ans=temp;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
            string temp=s.substr(l+1,r-l-1);
            if(ans.size()<temp.size())
            {
                ans=temp;
            }
        }
        return ans;
    }
};
