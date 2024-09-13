class Solution {
public:

    int longestString(int x, int y, int z) {
        int ans=0;
        if(z==0)
        {
            if(x==y)return 4*min(x,y);
            else return 4*min(x,y)+2;
        }
        else
        {
            int ans=2*z+4*min(x,y);
            if(x!=y)ans+=2;
            return ans;
        }
    }
};
