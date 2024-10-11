class Solution {
public:
    int smallestChair(vector<vector<int>>& a, int r) {
        int n=a.size();
        vector<int> exp=a[r];
        sort(a.begin(),a.end());
        vector<vector<int>> seat(n+1,vector<int>(2,-1));
        for(auto x:a)
        {   
            int mini=INT_MAX;
            for(int i=0;i<=n;i++)
            {
                if(seat[i][1]!=-1 && seat[i][1]<=x[0])
                {
                    seat[i][0]=-1;
                    seat[i][1]=-1;
                }
                if(seat[i][0]==-1)
                {
                    mini=min(mini,i);
                }
            }
            if(exp==x)
            {
                return mini;
            }
            seat[mini][0]=x[0];
            seat[mini][1]=x[1];
        }
        return n;
    }
};
