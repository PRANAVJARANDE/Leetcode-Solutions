class Solution {
  public:
  
    
    bool issafe(vector<int>&f1,vector<int>&f2)
    {
        for(int i=0;i<26;i++)
        {
            if(f1[i]>f2[i])return 0;
        }
        return 1;
    }
  
    string smallestWindow(string &s, string &p) 
    {
        vector<int>f1(26,0);
        for(int i=0;i<p.size();i++)f1[p[i]-'a']++;
        
        vector<int>f2(26,0);
        int ans=INT_MAX;
        int in=-1;
        int l=0;
        for(int i=0;i<s.size();i++)
        {
            f2[s[i]-'a']++;
            while(f2[s[l]-'a']>f1[s[l]-'a'])
            {
                f2[s[l]-'a']--;
                l++;
            }
            if(issafe(f1,f2))
            {
                ans=min(ans,i-l+1);
            }
        }
        
        if(ans==INT_MAX)return "";
        
        int sz=ans;
        vector<int>f3(26,0);
        for(int i=0;i<s.size();i++)
        {
            f3[s[i]-'a']++;
            if(i-sz>=0)f3[s[i-sz]-'a']--;
            if(i>=sz-1)
            {
                if(issafe(f1,f3))
                {
                    return s.substr(i-sz+1,sz);
                }
            }
        }
        return "";
    }
};
