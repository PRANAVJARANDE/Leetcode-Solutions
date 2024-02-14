class Solution {
public:
    string firstPalindrome(vector<string>& words) 
    {
        for(string s: words)
        {
            bool b=0;
            int n=s.size();
            for(int i=0;i<n/2;i++)
            {
                if(s[i]!=s[n-i-1])
                {
                    b=1;
                    break;
                }
            }
            if(b==0)
            {
                return s;
            }
        }
        return "";
    }
};
