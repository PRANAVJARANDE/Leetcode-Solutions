class Solution {
public:
    int isPrefixOfWord(string s, string a) {
        int n=s.size();
        int sz=a.size();
        int w=1;
        for(int i=0;i<=n-sz;i++)
        {
            if(i==0 || s[i-1]==' ')
            {
                if(s.substr(i,sz)==a)return w;
            }
            if(s[i]==' ')w++;
        }
        return -1;
    }
};
