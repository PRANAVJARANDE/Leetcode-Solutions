class Solution {
public:
    bool checkIfExist(vector<int>& a) {
        map<int,int> m;
        for(auto x: a)m[x]++;
        for(auto x: a)
        {
            if(x!=0 && m[2*x]!=0)
            {
                return 1;
            }
        }
        if(m[0]>=2)return 1;
        return 0;
    }
};
