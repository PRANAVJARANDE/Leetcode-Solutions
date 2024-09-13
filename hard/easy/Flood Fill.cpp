class Solution 
{
public:

    int m,n;
    vector<int> dir={-1,0,1,0,-1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
       m=image.size();
       n=image[0].size();
       queue<pair<int,int>> q;
       int oc=image[sr][sc];
       if(oc==color)
       {
            return image;
       }
       image[sr][sc]=color;
       q.push({sr,sc});
       
       while(!q.empty())
       {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int u=x+dir[i];
                int v=y+dir[i+1];
                if(u>=0 && u<m && v>=0 && v<n && image[u][v]==oc)
                {
                    image[u][v]=color;
                    q.push({u,v});
                }
            }
        }
       
        return image;

    }
};
