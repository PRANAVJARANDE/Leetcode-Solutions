class Solution {
public:

    bool check(vector<int>a,int k,int v)
    {
        int n=a.size();
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==v)continue;
            else
            {
                if(k>0)
                {
                    a[i+1]=a[i+1]*(-1);
                    a[i]=a[i]*(-1);
                    k--;
                }
                else
                {
                    return 0;
                }
            }
        }
        if(a[n-1]==v)return 1;
        return 0;
    }

    bool canMakeEqual(vector<int>& nums, int k) 
    {
        if(check(nums,k,1) || check(nums,k,-1))return 1;
        return 0;
    }
};
