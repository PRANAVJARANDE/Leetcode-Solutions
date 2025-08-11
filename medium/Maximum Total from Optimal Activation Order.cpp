#define ll long long
class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        ll ans=0;
        map<ll,priority_queue<ll>>m;
        for(int i=0;i<value.size();i++)m[limit[i]].push(value[i]);
        
        for(auto x:m)
        {
            for(int i=0;i<x.first && !x.second.empty();i++)
            {
                ans+=x.second.top();
                x.second.pop();
            }
        }
        return ans;
    }
};
