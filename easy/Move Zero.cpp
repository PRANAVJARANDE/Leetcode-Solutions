class Solution {
public:
    void moveZeroes(vector<int>& arr) 
    {
        int i=0;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[j]!=0)
            {
                arr[i]=arr[j];
                i++;
            }
        }

        for(;i<arr.size();i++)
        {
            arr[i]=0;
        }
    }
};
