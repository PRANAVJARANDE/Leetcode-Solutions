class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& arr, int k)
    {
        int n=arr.size();

        priority_queue<int, vector<int> ,greater<int>> q1;

        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                q1.push(arr[i][j]);
            }
        }

        for(int i=1;i<k;i++)
        {
            q1.pop();
        }

        return q1.top();
    }
};
