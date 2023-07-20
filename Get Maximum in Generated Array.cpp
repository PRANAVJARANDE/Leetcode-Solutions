class Solution {
public:
    int getMaximumGenerated(int n) 
    {
        if(n<2)
            return n;
        
        vector<int> arr(n+1,0);
        arr[0]=0,arr[1]=1;

        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(i%2==1)
            {
                arr[i]=arr[i/2]+arr[i/2 +1];
            }
            else
            {
                arr[i]=arr[i/2];
            }
            ans=max(arr[i],ans);
        }
        return ans;
    }
};
