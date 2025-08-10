#define ll long long
class Solution {
public:
    long long specialPalindrome(long long k) 
    {
        vector<ll>v1;
        ll ans=LLONG_MAX;
        for(ll i=0;i<(1ll<<9);i++)
        {
            ll l=0;
            ll odcnt=0;
            vector<ll>temp;
            for(ll j=0;j<9;j++)
            {
                if(i & (1ll<<j))
                {
                    l+=j+1;
                    if((j+1)%2)odcnt++;
                    temp.push_back(j+1);
                }
            }
            if(odcnt>1 || l>=17)continue;

            //generate all permutations of temp

            ll od=-1;
            vector<ll>pairs;
            for(auto x:temp)
            {
                ll rem=x/2;
                while(rem--)pairs.push_back(x);
                if(x%2)od=x;
            }

            do {
                ll sz=pairs.size();
                ll num=0;
                for(ll i=0;i<sz;i++)num=(num*10)+pairs[i]; 
                if(od!=-1)num=num*10+od;
                for(ll i=sz-1;i>=0;i--)num=(num*10)+pairs[i]; 
                if(num>k)ans=min(ans,num);
            } while (next_permutation(pairs.begin(), pairs.end()));
        }
        return ans;
    }
};
