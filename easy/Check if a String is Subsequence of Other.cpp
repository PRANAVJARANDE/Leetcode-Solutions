class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int i=0;
        for(auto x:s2)
        {
            if(i<s1.size() && s1[i]==x)
            {
                i++;
            }
        }
        return i==(int)s1.size();
    }
};
