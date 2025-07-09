class Solution {
public:

    int check_if_region(int i, int j, int th, vector<vector<int>>& a) 
    {
        for (int x = i-1; x <= i+1; x++) 
        {
            for (int y = j-1; y <= j+1; y++) 
            {
                if (y+1 <= j+1 && abs(a[x][y] - a[x][y+1]) > th) return -1;
                if (x+1 <= i+1 && abs(a[x][y] - a[x+1][y]) > th) return -1;
            }
        }
        int s=0;
        for(int x=i-1;x<=i+1;x++)
        {
            for(int y=j-1;y<=j+1;y++)
            {
                s+=a[x][y];
            }
        }
        return s/9;
    }
    
    vector<vector<int>> resultGrid(vector<vector<int>>& a, int th) 
    {
        int n=a.size();
        int m=a[0].size();
        vector<vector<vector<int>>>list(n,vector<vector<int>>(m));
        
        //go to each subgrid of size 9*9
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                int temp=check_if_region(i,j,th,a);
                if(temp!=-1)
                {
                    for(int x=i-1;x<=i+1;x++)
                    {
                        for(int y=j-1;y<=j+1;y++)
                        {
                            list[x][y].push_back(temp);
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int s=0;
                for(auto x:list[i][j])
                {
                    s+=x;
                }
                if(list[i][j].empty())
                {
                    continue;
                }
                a[i][j]=(s/(int)list[i][j].size());
            }
        }
        return a;
    }
};
