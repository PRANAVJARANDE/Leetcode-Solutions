class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) 
    {
        arr.insert(arr.begin(),0);
        arr.push_back(0);
        int ans=0;
        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i-1]==0 && arr[i]==0 && arr[i+1]==0)
            {
                arr[i]=1;
                ans++;
            }
        }
        if(ans>=n)
        {
            return 1;
        }
        return 0;
    }
};
