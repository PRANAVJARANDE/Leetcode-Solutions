class Solution {
public:
    string repeatLimitedString(string s, int dl) {
        int n=s.size();
        string ans(n,'0');
        vector<int>m(26,0);
        for(auto x:s)
        {
            m[x-'a']++;
        }
        int in=0;
        for(int i=25;i>=0;i--)
        {
            while(m[i]!=0)
            {
                int l=min(m[i],dl);
                while(l--)
                {
                    char ch='a'+i;
                    ans[in++]=ch;
                    m[i]--;
                }
                if(m[i]!=0)
                {
                    bool b=0;
                    for(int j=i-1;j>=0;j--)
                    {
                        if(m[j]!=0)
                        {
                            m[j]--;
                            char ch2=j+'a';
                            ans[in++]=ch2;
                            b=1;
                            break;
                        }
                    }
                    if(b==0)return ans.substr(0,in);
                }
            }
        }
        return ans;
    }
};
