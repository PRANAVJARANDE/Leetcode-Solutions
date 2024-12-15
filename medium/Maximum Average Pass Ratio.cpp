class Solution {
public:

    double helper(int a,int b)
    {
        double prev=(double)a/b;
        double nex=(a+1.0)/(b+1.0);
        return nex-prev;
    }

    double maxAverageRatio(vector<vector<int>>& a, int ex) {
        int n=a.size();
        priority_queue<pair<double,int>>q1;
        for(int i=0;i<n;i++)
        {
            q1.push({helper(a[i][0],a[i][1]),i});
        }

        while(ex--)
        {
            auto fr=q1.top();
            q1.pop();
            int in=fr.second;    
            a[in][0]++;
            a[in][1]++;
            q1.push({helper(a[in][0],a[in][1]),in});
        }
        
        double s=0;
        for(auto x:a)
        {
            double rat=(double)x[0]/x[1];
            s+=rat;
        }
        s/=n;
        return s;
    }
};
