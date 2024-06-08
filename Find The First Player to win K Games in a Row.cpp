class Solution {
public:
    int findWinningPlayer(vector<int>& a, int k) {
        int n=a.size();
        int wind=0;
        if(a[0]<a[1])
        {
            wind=1;
        }
        int wins=1;
        if(k==1)return wind;
        for(int i=2;i<n;i++)
        {
            if(a[wind]<a[i])
            {
                wind=i;
                wins=1;
            }
            else
            {
                wins++;
                if(wins==k)
                {
                    return wind;
                }
            }
        }
        return wind;
    }
};
