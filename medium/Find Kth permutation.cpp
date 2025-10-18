class Solution {
  public:
    
    int n;
    string helper(int in,int k,vector<int>&vis,vector<long long>&fact)
    {
        if(in>n)return "";
        int dig=fact[n-in];
        int req=k/dig;
        int rem=k%dig;

        string ta="";
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                if(req==0)
                {
                    vis[i]=1;
                    ta=to_string(i);
                    break;
                }
                req--;
            }
        }
        ta+=helper(in+1,rem,vis,fact);
        return ta;
    }
    
    string kthPermutation(int nn, int k) 
    {
        n=nn;
        k--;
        vector<long long>fact(10,1);
        for(long long i=2;i<10;i++)fact[i]=fact[i-1]*i;
        vector<int>vis(n+1,0);
        return helper(1,k,vis,fact);
    }
};
