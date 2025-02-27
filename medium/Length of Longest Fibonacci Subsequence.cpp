class Solution {
public:

    int lenLongestFibSubseq(vector<int>& a) 
    {
        int n=a.size();
        int ans=0;
        map<int,int>m;
        for(int i=0;i<n;i++)m[a[i]]=i;
        for(int prev=0;prev<n;prev++)
        {
            for(int in=prev+1;in<n;in++)
            {
                int a1=a[prev],a2=a[in];
                int len=2;
                while(m.find(a1+a2)!=m.end())
                {
                    int na2=a1+a2;
                    int na1=a2;
                    a1=na1;
                    a2=na2;
                    len++;
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};
