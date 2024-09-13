class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) 
    {
            vector<int> v1;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='1')
                {
                        v1.push_back(i);
                }
            }
            if(k==1)
            {
                    if(v1.size()!=0)
                            return "1";
                    
                    return "";
            }
            
            string ans="";
            int l=INT_MAX;
            k--;
            for(int i=k;i<v1.size();i++)
            {
                int nl=v1[i]-v1[i-k]+1;
                    if(nl<l)
                    {
                            ans=s.substr(v1[i-k],nl);
                            l=nl;
                    }
                    else if(nl==l)
                    {
                            string s1=s.substr(v1[i-k],nl);
                            if(s1.compare(ans)<0)
                            {
                                ans=s1;
                            }
                    }
            }
            return ans;
        
    }
};
