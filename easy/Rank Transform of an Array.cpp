class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>> m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]].push_back(i);
        }
        int in=1;
        for(auto x:m)
        {
            for(int y:x.second)
            {
                arr[y]=in;
            }
            in++;
        }
        return arr;
    }
};
