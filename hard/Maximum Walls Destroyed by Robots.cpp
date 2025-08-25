#define ll long long
class Solution {
public:

    int help(int l,int r,vector<int>&w) 
    {
        if(l>r)return 0;
        ll st=lower_bound(w.begin(),w.end(),l)-w.begin();
        ll en=upper_bound(w.begin(),w.end(),r)-w.begin();
        return en-st;
    }

    int maxWalls(vector<int>& robots,vector<int>& distance,vector<int>&w) 
    {
        int n=robots.size();
        vector<vector<ll>>r(n,vector<ll>(2,0));
        for(int i=0;i<n;i++)
        {
            r[i][0]=robots[i];      
            r[i][1]=distance[i];  
        }
        sort(r.begin(),r.end()); 
        sort(w.begin(),w.end()); 
        r.push_back({(ll)1e9,0}); 

        vector<vector<ll>>dp(n,vector<ll>(2,0));
        int lf=help(r[0][0]-r[0][1],r[0][0],w); 
        int rf=help(r[0][0],min(r[1][0]-1,r[0][0]+r[0][1]),w);

        for(int i=1;i<n;i++) 
        {
            int lfi=help(max(r[i][0]-r[i][1],r[i-1][0]+1),r[i][0],w);
            int rfi=help(r[i][0],min(r[i+1][0]-1,r[i][0]+r[i][1]),w);
            int common=help(max(r[i][0]-r[i][1],r[i-1][0]+1),min(r[i-1][0]+r[i-1][1],r[i][0]-1),w);
            int op1=lf+lfi; 
            int op2=rf+lfi-common;
            int op3=lf+rfi;
            int op4=rf+rfi;
            lf=max(op1,op2);
            rf=max(op3,op4);
        }

        return max(lf,rf);
    }
};
