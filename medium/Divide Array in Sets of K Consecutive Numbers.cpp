class Solution {
public:
    bool isPossibleDivide(vector<int>& a, int g) {
        sort(a.begin(),a.end());
        int n=a.size();
        if(n%g!=0)return 0;

        multiset<int> s1(a.begin(),a.end());
        while(!s1.empty())
        {
            int in=*s1.begin();
            int sz=g;
            while(sz--)
            {
                if(s1.find(in)!=s1.end())
                {
                    s1.erase(s1.find(in));
                    in++;
                }
                else
                {
                    return 0;
                }
            }
        }
        return 1;

    }
};
