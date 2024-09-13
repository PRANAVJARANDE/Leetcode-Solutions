class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n=s.size(),m=t.size();
        map<char,int> fre;
        for(int i=0;i<m;i++) fre[t[i]]++;
        
        int ele=fre.size();
        int l=0,r=0;
        int len=INT_MAX,st=0;
        
        while(r<n)
        {
            fre[s[r]]--;
            if(fre[s[r]]==0)
            {
                ele--;
            }

            if(ele==0)
            {
                while(ele==0)
                {
                    int yl=r-l+1;
                    if(yl<len)
                    {
                        len=yl;
                        st=l;
                    }
                    fre[s[l]]++;
                    if(fre[s[l]]>0)
                    {
                        ele++;
                    }
                    l++;
                }
            }
            r++;
        }
        if(len==INT_MAX)
        {
            return "";
        }
        return s.substr(st,len);
    }
};
