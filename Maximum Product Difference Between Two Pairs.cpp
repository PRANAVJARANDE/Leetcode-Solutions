class Solution {
public:
    int maxProductDifference(vector<int>& nums) 
    {
        int n=nums.size();
        int ma1=INT_MIN,ma2=INT_MIN;
        int mi1=INT_MAX,mi2=INT_MAX;
        for(int x: nums)
        {
            if(x>ma2)
            {
                ma1=ma2;
                ma2=x;
            }
            else if(x>ma1)
            {
                ma1=x;
            }

            if(x<mi1)
            {
                mi2=mi1;
                mi1=x;
            }
            else if(x<mi2)
            {
                mi2=x;
            }

        }
        return (ma1*ma2)-(mi1*mi2);
    }
};
