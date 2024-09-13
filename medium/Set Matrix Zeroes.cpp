class Solution {
public:
    void setZeroes(vector<vector<int>>&arr) 
    {
        int r=arr.size();
        int c=arr[0].size();

        set<int> v1;
        set<int> v2;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(arr[i][j]==0)
                {
                    v1.insert(i);
                    v2.insert(j);
                }
            }
        }

        //row
        for(int x: v1)
        {
            for(int i=0;i<r;i++)
            {
                if(i==x)
                {
                    for(int j=0;j<c;j++)
                    {
                        arr[i][j]=0;
                    }
                }
            }
        }

        for(int x: v2)
        {
            for(int i=0;i<c;i++)
            {
                if(i==x)
                {
                    for(int j=0;j<r;j++)
                    {
                        arr[j][i]=0;
                    }
                }
            }
        }
    }
};
