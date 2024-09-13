class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> q1;
        unordered_map<char,int> m;
        for(char x: s)
        {
            m[x]++;
        }
        for(auto x: m)
        {
            q1.push({x.second,x.first});
        }
        s="";
        while(!q1.empty())
        {
            for(int i=0;i<q1.top().first;i++)
            {
                s+=q1.top().second;
            }
            m.erase(q1.top().second);
            q1.pop();
        }
        m.clear();
        return s;
    }
};
