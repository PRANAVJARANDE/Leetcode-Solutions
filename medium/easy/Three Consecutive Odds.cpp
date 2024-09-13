class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        for(int x: arr)
        {
            if(x%2==0)cnt=0;
            else{
                cnt++;
                if(cnt==3)return 1;
            }
        }
        return 0;
    }
};
