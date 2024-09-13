class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int t) 
    {
        int n=arr.size();
        vector<vector<int>> ans;
        set<multiset<int>> s1;

        sort(arr.begin(),arr.end());

        for(int i=0;i<n-3;i++)
        {
            int tn=t-arr[i];
            for(int j=i+1;j<n-2;j++)
            {
                int l=j+1;
                int r=n-1;
                multiset<int> v1;
                while(l<r)
                {
                    long long int sum=arr[i];
                    sum=sum+arr[j];
                    sum=sum+arr[l];
                    sum=sum+arr[r];
                    if(sum==t)
                    {
                        v1.insert(arr[i]);
                        v1.insert(arr[j]);
                        v1.insert(arr[l]);
                        v1.insert(arr[r]);
                        s1.insert(v1);
                        l++;
                        r--;
                        v1.clear();
                    }
                    else if(sum>t)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }

        for(auto x: s1)
        {
            vector<int> v1;
            for(auto y: x)
            {
                v1.push_back(y);
            }
            ans.push_back(v1);
        }
        return ans;
    }
};
