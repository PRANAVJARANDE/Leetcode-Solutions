class Solution {
public:

    int helper(string s,int k,char ch)
    {
        int n=s.size();
        int res=0;
        for(int i=0;i<k;i++)
        {
            if(s[i]!=ch)res++;
        }
        int ans=res;
        for(int i=k;i<n;i++)
        {
            if(s[i-k]!=ch)res--;
            if(s[i]!=ch)res++;
            ans=min(ans,res);
        }
        return ans;
    }

    int minimumRecolors(string s, int k) 
    {
        int a1=helper(s,k,'B');
        //int a2=helper(s,k,'W');
        return a1;
    }
};
