class Solution {
public:
    vector<int> evenOddBit(int n) 
    {
        int k=0;
        vector<int> ans(2,0);
        while(n!=0)
        {
            if(n%2==1)
            {
                //element found
                ans[k%2]++;
            }

            k++;
            n=n>>1;
        }
        return ans;
    }
};
