class Solution {
public:

    int n;
    bool check(int ans,string s,int k)
    {
        int a=0,b=0,c=0;
        for(int i=0;i<ans;i++)
        {
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;
        }
        if(a>=k && b>=k && c>=k)return 1;
        int in=ans-1;
        int j=n-1;
        while(in>=0)
        {
            if(s[in]=='a')a--;
            else if(s[in]=='b')b--;
            else c--;
            if(s[j]=='a')a++;
            else if(s[j]=='b')b++;
            else c++;

            if(a>=k && b>=k && c>=k)return 1;
            in--;
            j--;
        }
        return 0;

    }




    int takeCharacters(string s, int k) {
        if(k==0)return 0;
        int ans=-1;
        n=s.size();
        int l=1,r=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,s,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
