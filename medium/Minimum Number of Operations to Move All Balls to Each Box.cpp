class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.size();
        vector<int>ps(n,0),ss(n,0);
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i+1<n)ss[i]=ss[i+1]+cnt;
            if(s[i]=='1')cnt++;
        }
        cnt=0;
        for(int i=0;i<n;i++)
        {
            if(i-1>=0)ps[i]=ps[i-1]+cnt;
            if(s[i]=='1')cnt++;
        }

        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=ps[i]+ss[i];
        }
        return ans;


    }
};
