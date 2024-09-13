class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) 
    {
        vector<int> v1;
        int r=arr.size();
        int c=arr[0].size();

    
        int rst=0;
        int cst=0;
        int rend=r-1;
        int cend=c-1;     

        while(rst<=rend && cst<=cend)
        {
            
            for(int i=cst;i<=cend;i++)
            {
                v1.push_back(arr[rst][i]);
            }
            
            rst++;
            if(rst>rend)
            {
                break;
            }

            for(int i=rst;i<=rend;i++)
            {
                v1.push_back(arr[i][cend]);
            }
            cend--;
            if(cst>cend)
            {
                break;
            }


            for(int i=cend;i>=cst;i--)
            {
                v1.push_back(arr[rend][i]);
            }
            rend--;
            if(rst>rend)
            {
                break;
            }

            for(int i=rend;i>=rst;i--)
            {
                v1.push_back(arr[i][cst]);
            }
            cst++;
            if(cst>cend)
            {
                break;
            }


        }


        return v1;
        
    }
};
