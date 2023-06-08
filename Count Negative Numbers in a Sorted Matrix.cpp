O(n2)

class Solution {
public:

    int hp(vector<vector<int>>&arr,int i,int j)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(arr[i][j]>=0)
        {
            return 0;
        }
        arr[i][j]=0;
        int c=1+hp(arr,i-1,j)+hp(arr,i,j-1);
        return c;
    }

    int countNegatives(vector<vector<int>>& grid) 
    {
        return hp(grid,grid.size()-1,grid[0].size()-1);
    }
};


//O(m*log(n);
class Solution {
public:

    int countNegatives(vector<vector<int>>& grid) 
    {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            int a=grid[i].end() - upper_bound(grid[i].begin(),grid[i].end(),0,greater<int>());
            ans+=a;
        }
        return ans;
    }
};
