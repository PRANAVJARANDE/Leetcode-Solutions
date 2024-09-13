class Solution {
public:
    bool checkArray(vector<int>& arr, int k) 
    {
        vector<int> temp(k,0);
        for(int i=0;i<arr.size();i++)
        {
            temp[i%k]+=arr[i];
        }
        for(int i=1;i<k;i++)
        {
            if(temp[i]!=temp[0])
            {
                return 0;
            }
        }
        return 1;
    }
};
