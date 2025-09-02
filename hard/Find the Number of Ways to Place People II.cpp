class Solution {
public:

    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]!=b[0])return a[0]<b[0];
        return a[1]>b[1];
    }

    int numberOfPairs(vector<vector<int>>& a) 
    {
        sort(a.begin(),a.end(),cmp);
        map<int,int>m;
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {   
            int x=a[i][0],y=a[i][1];
            int maxi=INT_MIN;
            auto itr=m.lower_bound(y);
            while(itr!=m.end())
            {
                auto temp=(*itr).second;
                if(temp>maxi)
                {
                    ans++;
                    maxi=temp;
                }
                itr++;
            }
            if(m.find(y)==m.end())m[y]=x;
            else m[y]=max(m[y],x);
        }
        return ans;
    }
};
