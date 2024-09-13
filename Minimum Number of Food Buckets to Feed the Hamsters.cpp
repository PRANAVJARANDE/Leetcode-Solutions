//APPLIED GREEDY TECHNIQUE TOO GET ANSS
class Solution {
public:
    int minimumBuckets(string s) 
    {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='H')
            {
                if(i!=0 && s[i-1]=='f')
                {
                    continue;
                }
                else if(i!=n-1 && s[i+1]=='.')
                {
                    ans++;
                    s[i+1]='f';
                }
                else if(i!=0 && s[i-1]=='.')
                {
                    ans++;
                    s[i-1]='f';
                }
                else
                {
                    return -1;
                }
            }
        }
        return ans;
        
    }
};
