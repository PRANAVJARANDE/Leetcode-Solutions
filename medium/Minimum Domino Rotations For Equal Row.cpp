class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) 
    {
        int ans=INT_MAX;
        int n=b.size();
        for(int c=1;c<=6;c++)
        {
            //top
            bool f=0;
            int c1=0,c2=0;
            for(int j=0;j<n;j++)
            {
                if(a[j]!=c && b[j]!=c)
                {
                    f=1;
                    break;
                }
                if(a[j]!=c && b[j]==c)c1++;
                if(b[j]!=c && a[j]==c)c2++;
            }
            if(f==0)
            {
                ans=min(ans,min(c1,c2));
            }
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
