class Solution {
public:
    int getLucky(string s, int k) {
        string h="";
        for(char x: s)
        {
            int v=(int)x-'a'+1;
            h+=to_string(v);
        }
        int f=0;
        k--;
        for(char x: h)
        {
            f+=x-'0';
        }
        
        while(k--)
        {
            int yu=0;
            while(f!=0)
            {
                yu+=f%10;
                f/=10;
            }
            f=yu;
        }
        return f;
    }
};
