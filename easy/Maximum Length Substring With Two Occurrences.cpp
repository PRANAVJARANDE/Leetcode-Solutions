class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        int ans=1;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                map<char,int> m;
                bool b=0;
                for(int z=i;z<=j;z++)
                {   
                    m[s[z]]++;
                    if(m[s[z]]>2)
                    {
                        b=1;
                        break;
                    }
                }
                if(b==0)
                {
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
