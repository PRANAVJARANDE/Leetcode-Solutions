class Solution {
public:
    int accountBalanceAfterPurchase(int n) 
    {
            int k=n%10;
            if(k<=4)
            {
                    return 100-n+k;
            }
            else
            {
                    return 90-n+k;
            }
        
    }
};
