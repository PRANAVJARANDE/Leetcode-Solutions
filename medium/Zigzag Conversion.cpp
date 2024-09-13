class Solution {
public:
    string convert(string s, int n) 
    {
        if(n==1)
        {
            return s;
        }
        vector<string> seq(n,"");
        int d=-1;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(j==n-1 || j==0)
            {
                d=-d;
            }

            seq[j]=seq[j]+s[i];
            if(d==1)
            {
                j++;
            }
            else
            {
                j--;
            }
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            ans=ans+seq[i];
        }
        return ans;
    }
};
