class Solution {
public:
    int numberOfPairs(vector<vector<int>>& a) 
    {
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                int x1=a[i][0],y1=a[i][1];
                int x2=a[j][0],y2=a[j][1];
                if(x1<=x2 && y1>=y2)
                {
                    //check
                    bool flag=0;
                    for(int z=0;z<n;z++)
                    {
                        if(z!=i && z!=j)
                        {
                            if(x1<=a[z][0] && a[z][0]<=x2 && y2<=a[z][1] && a[z][1]<=y1)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag==0)ans++;
                }
            }
        }
        return ans;
    }
};
