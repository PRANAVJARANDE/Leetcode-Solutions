class Solution {
public:
    bool canChange(string s, string t) {
        int n=s.size();
        string st="";
        for(auto x:s)
        {
            if(x!='_')st+=x;
        }
        string stt="";
        for(auto x:t)
        {
            if(x!='_')stt+=x;
        }
        if(st!=stt)return 0;
        int r=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')r++;
            else if(s[i]=='L')
            {
                if(r!=0)return 0;
            }
            if(t[i]=='R')
            {
                if(r==0)return 0;
                r--;
            }
        }

        int l=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='L')l++;
            else if(s[i]=='R')
            {
                if(l!=0)return 0;
            }
            if(t[i]=='L')
            {
                if(l==0)return 0;
                l--;
            }
        }
        return 1;      
    }
};
