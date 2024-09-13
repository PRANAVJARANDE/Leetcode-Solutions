class Solution {
public:
    int n,xmax;

    bool getbit(int i,int j)
    {
        return i & 1<<j;
    }


    int countMaxOrSubsets(vector<int>& nums) 
    {
        n=nums.size();
        xmax=0;
        for(int i=0;i<n;i++)
        {
            xmax=xmax | nums[i];
        }
        int ans=0;
        for(int i=0;i<pow(2,n);i++)
        {
            int x=0;
            for(int j=0;j<n;j++)
            {
                if(getbit(i,j))
                {
                    x=x | nums[j];
                }
            }
            if(x==xmax)
            {
                ans++;
            }
        }
        return ans;

        
    }
};
