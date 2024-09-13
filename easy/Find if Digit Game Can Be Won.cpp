class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int d1=0,d2=0;
        for(int x:nums)
        {
            if(x/10==0)
            {
                d1+=x;
            }
            else
            {
                d2+=x;
            }
        }
        if(d1==d2)
        {
            return 0;
        }
        return 1;
    }
};
