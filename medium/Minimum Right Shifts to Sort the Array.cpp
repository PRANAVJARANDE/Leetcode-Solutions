class Solution {
public:
    int countPairs(vector<vector<int>>& arr, int k) 
    {
        map<pair<int,int>,int> m;
        int n=arr.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            int x1=arr[i][0],y1=arr[i][1];
            for(int j=0;j<=k;j++)
            {
                int x2=j^x1;
                int y2=(k-j)^y1;
                ans+=m[{x2,y2}];
            }
            m[{x1,y1}]++;
        }
        return ans;
    }
};
