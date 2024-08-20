class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> ans(9,0);
        ans[0]=1;
        ans[1]=ans[0]*9;
        ans[2]=ans[1]*9;
        ans[3]=ans[2]*8;
        ans[4]=ans[3]*7;
        ans[5]=ans[4]*6;
        ans[6]=ans[5]*5;
        ans[7]=ans[6]*4;
        ans[8]=ans[7]*3;
        for(int i=1;i<9;i++)
        {
            ans[i]=ans[i-1]+ans[i];
        }
        return ans[n];
    }
};
