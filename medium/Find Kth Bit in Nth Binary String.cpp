class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<n;i++)
        {
            int sz=s.size();
            s+="1";
            for(int j=sz-1;j>=0;j--)
            {
                if(s[j]=='0')s+="1";
                else s+="0";
            }
        }

        return s[k-1];
    }
};
