class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int x: arr)
        m[x]++;
        priority_queue<pair<int,int>> q1;
        for(auto x:m)
        {
            q1.push({x.second,x.first});
        }
        int ans=0;
        int s=0;
        int t=arr.size()/2;
        while(s<t)
        {
            ans++;
            s=s+q1.top().first;
            q1.pop();
        }
        return ans;
    }
};
