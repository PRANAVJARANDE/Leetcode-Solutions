class Solution {
public:
    string shortestPalindrome(string s) 
    {
        string ans="",res="";
        int n=s.size();
        for(int i=(n-1)/2;i>=0;i--)
        {
            int l=i-1;
            int r=i+1;
            while(l>=0 && s[l]==s[r])
            {
                l--;
                r++;
            }
            if(l<0)
            {
                if(r<n)
                {
                    ans=s.substr(r);
                }
                reverse(ans.begin(),ans.end());
                ans+=s;
                break;
            }
        }
        for(int i=(n/2)-1;i>=0;i--)
        {
            int l=i;
            int r=i+1;
            while(l>=0 && s[l]==s[r])
            {
                l--;
                r++;
            }
            if(l<0)
            {
                if(r<n)
                {
                    res=s.substr(r);
                }
                reverse(res.begin(),res.end());
                res+=s;
                break;
            }
        }
        if(res=="")return ans;
        if(ans=="")return res;
        if(ans.size()>res.size())return res;
        return ans;
    }
};
