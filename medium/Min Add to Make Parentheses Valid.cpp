class Solution {
  public:
    int minParentheses(string& s) 
    {
        int ans=0;
        int cnt=0;
        for(auto x:s)
        {
            if(x=='(')cnt++;
            else cnt--;
            if(cnt<0)
            {
                cnt=0;
                ans++;
            }
        }
        ans+=cnt;
        return ans;
    }
};
