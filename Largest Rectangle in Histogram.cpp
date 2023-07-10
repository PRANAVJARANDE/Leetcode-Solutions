class Solution {
public:
    int largestRectangleArea(vector<int>& arr) 
    {
        stack<int> s1;
        arr.push_back(0);
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            
            while(!s1.empty() && arr[s1.top()]>arr[i])
            {
                int l=arr[s1.top()];
                s1.pop();
                int b;
                if(s1.empty())
                {
                    b=-1;
                }
                else
                {
                    b=s1.top();
                }
                ans=max(ans,l*(i-b-1));
                
            }
            s1.push(i);
        }
        return ans;
    }
};
