class Solution {
public:
    int countHomogenous(string s) 
    {
        int k=1;
        long long ans=0;
        long long M=7+1e9;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                k++;
            }
            else
            {
                ans=ans+(1LL*k*(k+1))/2;
                k=1;
            }
        }
        ans=ans+(1LL*k*(k+1))/2;
        return ans%M;
        
    }
};
