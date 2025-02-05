class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i1=-1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                if(i1==-1)i1=i;
                else
                {
                    swap(s2[i],s2[i1]);
                    break;
                }
            }
        }
        if(s1==s2)return 1;
        return 0;
    }
};
