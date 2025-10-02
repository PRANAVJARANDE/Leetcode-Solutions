class Solution {
public:
    int maxBottlesDrunk(int n, int e) 
    {
        int ans=0;
        int empty=0;
        while(n)
        {
            ans+=n;
            empty+=n;
            n=0;
            while(empty>=e)
            {
                empty-=e;
                n++;
                e++;
            }
        }
        return ans;
    }
};
