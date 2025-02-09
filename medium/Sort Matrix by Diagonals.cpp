class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& a) 
    {
        int n=a.size();
        for(int i=1;i<n;i++)
        {
            vector<int>v1;
            int x=0,y=i;
            while(x<n && y<n)
            {
                v1.push_back(a[x][y]);
                x++;
                y++;
            }
            sort(v1.begin(),v1.end());
            x=0,y=i;
            int in=0;
            while(x<n && y<n)
            {
                a[x][y]=v1[in];
                in++;
                x++;
                y++;
            }
        }
        for(int i=0;i<n;i++)
        {
            vector<int>v1;
            int x=i,y=0;
            while(x<n && y<n)
            {
                v1.push_back(a[x][y]);
                x++;
                y++;
            }
            sort(v1.begin(),v1.end(),greater<int>());
            x=i,y=0;
            int in=0;
            while(x<n && y<n)
            {
                a[x][y]=v1[in];
                in++;
                x++;
                y++;
            }
        }
        return a;
        
    }
};
