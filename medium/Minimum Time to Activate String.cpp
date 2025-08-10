#define ll long long
class Solution {
public:
    int minTime(string s, vector<int>& a, int k) 
    {
        ll n=s.size();
        ll cnt=0;
        set<ll>s1;
        s1.insert(-1);
        s1.insert(n);
        ll tm=0;
        for(auto x:a)
        {
            auto it1=s1.lower_bound(x);
            ll after=*it1;
            it1--;
            ll before=*it1;

            ll c1=x-before;
            ll c2=after-x;

            cnt+=c1*c2;
            s1.insert(x);
            if(cnt>=k)return tm;
            tm++;
        }
        return -1;
    }
};
