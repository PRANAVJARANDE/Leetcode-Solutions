class Solution {
public:
    bool rotateString(string s, string g) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string res=s.substr(i)+s.substr(0,i);
            if(res==g)return 1;
        }
        return 0;
    }
};
