class Solution {
  public:
    
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,1,-1};
    vector<char>dir{'U','D','R','L'};
    
    int n;
    void helper(int i,int j,string&v1,vector<string>&ans,vector<vector<int>>&a)
    {
        if(i<0 || j<0 || i>=n || j>=n || a[i][j]==2 || a[i][j]==0)return;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(v1);
            return;
        }
        //a[i][j]=1;
        a[i][j]=2;
        for(int z=0;z<4;z++)
        {
            v1.push_back(dir[z]);
            helper(i+dx[z],j+dy[z],v1,ans,a);
            v1.pop_back();
        }
        a[i][j]=1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& a) 
    {
        n=a.size();
        vector<string>ans;
        string v1="";
        helper(0,0,v1,ans,a);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
