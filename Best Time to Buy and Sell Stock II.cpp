class Solution {
public:

    int helper(vector<int>&arr,int i,bool b,int dest)
    {
        if(i>=dest)
            return 0;

        if(b)
        {
            int sell=-arr[i]+helper(arr,i+1,0,dest);
            int notsell=helper(arr,i+1,1,dest);
            return max(sell,notsell);
        }
        
        int buy=arr[i]+helper(arr,i+1,1,dest);
        int notbuy=helper(arr,i+1,0,dest);
        return max(buy,notbuy);
    }


    int maxProfit(vector<int>&arr) {
        vecctor<int
        return helper(arr,0,1,arr.size());
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans=0;
        for(int i=1;i<prices.size();i++)
        {
            ans+=max(prices[i]-prices[i-1],0);
        }
        return ans;
    }
};
