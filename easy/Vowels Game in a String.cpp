class Solution {
public:
    bool doesAliceWin(string s) 
    {
        int vc=0;
        for(auto x:s)if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')vc++;
        if(vc==0)return 0;
        return 1;
    }
};
