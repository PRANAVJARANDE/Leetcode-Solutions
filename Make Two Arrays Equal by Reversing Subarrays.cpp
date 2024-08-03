class Solution {
public:
    bool canBeEqual(vector<int>& a, vector<int>& b) {
        map<int,int> m;
        for(int x: a)m[x]++;
        for(int y: b)
        {
            if(m.find(y)!=m.end())
            {
                m[y]--;
                if(m[y]==0)
                {
                    m.erase(y);
                }
            }
            else
            {
                return 0;
            }
        }
        if(m.size()==0)
        {
            return 1;
        }
        return 0;
    }
};
