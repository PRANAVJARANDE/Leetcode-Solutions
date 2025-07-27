#define ll long long
class Solution {
public:
    long long numOfSubsequences(string s) 
    {
        ll n=s.size();
        vector<ll>ps(n,0),nx(n,0);
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='L')ps[i]++;
            if(i-1>=0)ps[i]+=ps[i-1];
        }
        for(ll i=n-1;i>=0;i--)
        {
            if(s[i]=='T')nx[i]++;
            if(i+1<n)nx[i]+=nx[i+1];
        }

        // for(auto x:ps)cout<<x<<" ";
        // cout<<endl;

        // for(auto x:nx)cout<<x<<" ";
        // cout<<endl;
        
        ll maxi=0;
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='C')ans+=(ps[i]*nx[i]);
            maxi=max(maxi,ps[i]*nx[i]);
        }
        //cout<<ans<<endl;
        
        ll op1=ans+maxi;
        ll op2=ans;
        ll lc=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')lc++;
            if(s[i]=='C')op2+=lc;
        }

        ll op3=ans;
        ll tc=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='T')tc++;
            if(s[i]=='C')op3+=tc;
        }
        return max(op1,max(op2,op3));
    }
};©leetcode
