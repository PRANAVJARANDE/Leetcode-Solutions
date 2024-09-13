class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) 
    {
        
        arr.push_back(INT_MAX);
        int n=arr.size();
        priority_queue<pair<int,int>> q1;
        sort(arr.begin(),arr.end());

        int c=1;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
                c++;
            }
            else
            {
                q1.push(make_pair(c,arr[i]));
                c=1;
            }
        }

        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            if(q1.empty())
            {
                break;
            }
            int k=q1.top().second;
            ans.push_back(k);
            q1.pop();
        }
        return ans;

        
    }
};
