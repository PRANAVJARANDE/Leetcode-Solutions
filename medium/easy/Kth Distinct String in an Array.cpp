class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> m;
        for(auto x: arr)
        {
            m[x]++;
        }
        int in=0;
        for(auto x:arr)
        {
            if(m[x]==1)
            {
                in++;
                if(in==k)
                {
                    return x;
                }
            }
        }
        return "";
    }
};
