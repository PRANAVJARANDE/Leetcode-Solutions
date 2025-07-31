class Solution {
public:
    int subarrayBitwiseORs(vector<int>& a) 
    {
        set<int>res,cur;
        for(auto x:a)
        {
            set<int>s1;
            s1.insert(x);
            res.insert(x);
            for(auto z:cur)
            {
                s1.insert(x | z);
                res.insert(x | z);
            }
            cur=s1;
        }
        return res.size();
    }
};
