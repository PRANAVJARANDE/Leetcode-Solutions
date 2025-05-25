class Solution {
public:
    int longestPalindrome(vector<string>& w) 
    {
        map<string,int>m;
        for(auto x:w)m[x]++;
        
        int ans=0;
        bool b=0;
        for(auto x:m)
        {
            if(x.first[0]==x.first[1])
            {
                ans+=x.second;
                if(x.second%2)
                {
                    if(b==0)b=1;
                    else ans--;
                }
            }
        }

        ans*=2;
        
        for(char ch1='a';ch1<='z';ch1++)
        {
            for(char ch2=ch1+1;ch2<='z';ch2++)
            {
                string r1=string()+ch1+ch2;
                string r2=string()+ch2+ch1;
                ans+=(min(m[r1],m[r2])*4);
            }
        }
        return ans;
    }
};
