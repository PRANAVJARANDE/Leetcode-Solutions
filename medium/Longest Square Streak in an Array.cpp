class Solution {
public:
    int longestSquareStreak(vector<int>& a) {
        sort(a.begin(),a.end());
        map<int,int> m;
        for(int x:a)m[x]++;
        int n=a.size();
        long long maxi=a[n-1];
        long long ans=1;
        for(int x:a)
        {
            long long res=0;
            long long r=x;
            while(r<=maxi)
            {
                if(m[r]!=0)res++;
                else break;
                r*=r;
            }
            ans=max(ans,res);
        }
        if(ans==1)ans=-1;
        return ans;
    }
};
