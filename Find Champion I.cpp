class Solution {
public:
    int findChampion(vector<vector<int>>& arr) 
    {
            int n=arr.size();
        for(int i=0;i<n;i++)
        {
                bool b=0;
                for(int j=0;j<n;j++)
                {
                        if(i!=j)
                        {
                                if(arr[i][j]==0)
                                {
                                        b=1;
                                        break;
                                }
                        }
                }
                if(b==0)
                {
                        return i;
                }
        }
        return -1;
    }
};
