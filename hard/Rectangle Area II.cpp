#define ll long long
class Solution {
public:

    const ll MOD=1E9 + 7; 
    int rectangleArea(vector<vector<int>>& a) 
    {
        set<ll>xsec;
        for(auto x:a)
        {
            xsec.insert(x[0]);
            xsec.insert(x[2]);
        }
        vector<ll>v1;
        for(auto x:xsec)v1.push_back(x);

        ll ans=0;
        for(ll i=0;i<v1.size()-1;i++)
        {
            ll l=v1[i];
            ll r=v1[i+1];

            vector<pair<ll,ll>>ysec;
            for(auto x:a)
            {
                if(x[0]<=l && r<=x[2])
                {
                    ysec.push_back({x[1],0});   //start
                    ysec.push_back({x[3],1});   //end
                }
            }
            sort(ysec.begin(),ysec.end());
            int cnt=0;
            int st=0;
            for(auto x:ysec)
            {
                if(cnt==0)st=x.first;
                if(x.second==0)cnt++;
                else cnt--;

                if(cnt==0)
                {
                    ans=((ans%MOD) + (((r-l)%MOD) * (x.first-st)%MOD)%MOD )%MOD;
                }
            }
        }
        return ans;
    }
};
