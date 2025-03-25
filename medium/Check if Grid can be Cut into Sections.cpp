class Solution {
public:
    bool checkValidCuts(int nn, vector<vector<int>>& a)
    {
        vector<vector<int>>x,y;
        for(auto z:a)
        {
            x.push_back({z[0],z[2]});
            y.push_back({z[1],z[3]});
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        int c1=0,c2=0;
        int n=a.size();
        int xmax=x[0][1];
        int ymax=y[0][1];
        for(int i=1;i<n;i++)
        {
            if(xmax<=x[i][0])
            {
                c1++;
                if(c1==2)return 1;
            }
            if(ymax<=y[i][0])
            {
                c2++;
                if(c2==2)return 1;
            }
            xmax=max(xmax,x[i][1]);
            ymax=max(ymax,y[i][1]);
        }
        return 0;
    }
};
