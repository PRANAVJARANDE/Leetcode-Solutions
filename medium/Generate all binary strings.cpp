#define ll long long
class Solution {
  public:
    vector<string> binstr(int n) 
    {
        vector<string>ans;
        for(ll i=0;i<(1ll<<n);i++)
        {
            string res(n,'0');
            ll temp=i;
            ll in=n-1;
            while(temp && in>=0)
            {
                if(temp%2)res[in]='1';
                in--;
                temp/=2;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
