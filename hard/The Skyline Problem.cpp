class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& arr) 
    {
        vector<vector<int>> v1;
        for(auto x: arr)
        {
            v1.push_back({x[0],-x[2]});
            v1.push_back({x[1],x[2]});
        }
        sort(v1.begin(),v1.end());

        vector<vector<int>>ans;
        multiset<int> s1;
        s1.insert(0);
        int curr=0;
        for(auto x: v1)
        {
            if(x[1]<0)
            {
                s1.insert(-x[1]);
            }
            else
            {
                s1.erase(s1.find(x[1]));
            }

            int y=*s1.rbegin();
            if(curr!= y)
            {
                curr=y;
                ans.push_back({x[0],curr});
            }
        }
        return ans;
    }
};
