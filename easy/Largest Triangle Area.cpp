class Solution {
public:

    double calc_dis(double x1,double y1,double x2,double y2)
    {
        double d=((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
        return sqrt(d);
    }

    double largestTriangleArea(vector<vector<int>>& a) 
    {
        double ans=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    double x1=a[i][0],y1=a[i][1];
                    double x2=a[j][0],y2=a[j][1];
                    double x3=a[k][0],y3=a[k][1];
                    double d1 = calc_dis(x1,y1,x2,y2);
                    double d2 = calc_dis(x2,y2,x3,y3);
                    double d3 = calc_dis(x3,y3,x1,y1);
                    double s = (d1 + d2 + d3) / 2.0;
                    double area = sqrt(s * (s - d1) * (s - d2) * (s - d3));
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
