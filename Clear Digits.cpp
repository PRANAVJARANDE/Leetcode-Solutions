class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        string ans="";
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            char x=s[i];
            if(x<='9' && x>='0')
            {
                cnt++;
            }
            else 
            {
                cnt--;
                if(cnt<0)
                {
                    ans=ans+x;
                    cnt=0;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
