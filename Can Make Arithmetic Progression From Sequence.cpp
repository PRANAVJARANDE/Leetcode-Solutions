class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1;i>0;i--)
        {
            arr[i]=arr[i]-arr[i-1];
        }
        int k=arr[1];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]!=k)
            {
                return 0;
            }
        }
        return 1;
    }
};
