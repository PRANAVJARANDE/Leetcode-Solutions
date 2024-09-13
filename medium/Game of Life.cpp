class Solution {
public:


    int cow(vector<vector<int>>& arr,int i,int j)
    {
        int r=arr.size();
        int c=arr[0].size();

        int k=0; 
        if(j>=1 && i>=1 && arr[i-1][j-1]==1 )
        {
            k++;
        }
        if(i>=1  && arr[i-1][j]==1)
        {
            k++;
        }
        if(j+1<c && i-1>=0 && arr[i-1][j+1]==1)
        {
            k++;
        }
        if(j-1>=0 && arr[i][j-1]==1)
        {
            k++;
        }
        if(j+1<c && arr[i][j+1]==1)
        {
            k++;
        }
        if(j-1>=0 && i+1<r && arr[i+1][j-1]==1)
        {
            k++;
        }
        if(i+1<r && arr[i+1][j]==1 )
        {
            k++;
        }
        if(i+1<r && j+1<c && arr[i+1][j+1]==1)
        {
            k++;
        }

        return k;
    }

    void gameOfLife(vector<vector<int>>&arr) 
    {
        int r=arr.size();
        int c=arr[0].size();

        vector<vector<int>> v1;
        v1=arr;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int hh=cow(v1,i,j);
                if(v1[i][j]==1)
                {
                if(hh<2)
                {
                    arr[i][j]=0;
                }
                else if(hh>=4)
                {
                    arr[i][j]=0;
                }
                else
                {
                    arr[i][j]=1;
                }
                }
                else
                {
                    if(hh==3)
                    {
                        arr[i][j]=1;
                    }
                }

            }
        }
        
    }
};

