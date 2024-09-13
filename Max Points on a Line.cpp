class Solution {
public:
    int maxPoints(vector<vector<int>>& arr) 
    {
        int n=arr.size(),ans=1;
        for(int i=0;i<n;i++)
        {
            unordered_map<float,int> m;
            for(int j=i+1;j<n;j++)
            {
                double x1=arr[i][0],y1=arr[i][1],x2=arr[j][0],y2=arr[j][1];
                if(x2==x1)
                {
                    m[INT_MAX]++;
                    continue;
                }
                float s=(y2-y1)/(x2-x1);
                m[s]++;
            }
            for(auto x: m)
            {
                ans=max(ans,x.second+1);
            }
        }
        return ans;   
    }
};
