class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        for(int x:arr1)m[x]++;
        int in=0;
        for(int x:arr2)
        {
            while(m[x]--)
            {
                arr1[in]=x;
                in++;
            }
            m.erase(x);
        }
        for(auto x: m)
        {
            while(x.second--)
            {
                arr1[in]=x.first;
                in++;
            }
        }
        return arr1;
    }
};
