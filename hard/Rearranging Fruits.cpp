class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2)
    {
        long long mini=INT_MAX;
        map<long long,long long>m1,m2,tot;
        for(auto x:b1)
        {
            mini=min(mini,(long long)x);
            tot[x]++;
            m1[x]++;
        }
        for(auto x:b2)
        {
            mini=min(mini,(long long)x);
            tot[x]++;
            m2[x]++;
        }
        long long sum=0;
        map<int,int>diff;
        for(auto x:tot)
        {
            if(x.second%2)return -1;
            diff[x.first]=abs(m1[x.first]-m2[x.first])/2;
            sum+=diff[x.first];
        }
        sum/=2;
        
        long long ans=0;
        for(auto x:diff)
        {
            long long tm=min((long long)sum,(long long)x.second);
            ans+=(min((long long)x.first,(long long)mini*2))*(tm);
            sum-=tm;
        }
        return ans;
    }
};
