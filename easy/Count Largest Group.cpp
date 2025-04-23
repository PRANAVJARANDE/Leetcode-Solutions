class Solution {
public:
    int countLargestGroup(int n) 
    {
        map<int,int>m;
        for(int i=1;i<=n;i++)
        {
            int d=i;
            int s=0;
            while(d)
            {
                s+=d%10;
                d/=10;
            }
            m[s]++;
        }
        map<int,int>m2;
        int maxi=0;
        for(auto x:m)
        {
            m2[x.second]++;
            maxi=max(maxi,x.second);
        }
        return m2[maxi];
    }
};
