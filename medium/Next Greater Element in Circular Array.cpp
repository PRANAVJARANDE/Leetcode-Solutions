// OA Perspective
class Solution {
  public:
    vector<int> nextGreater(vector<int> &a) 
    {
        int n=a.size();
        for(int i=0;i<n;i++)a.push_back(a[i]);
        stack<int>s1;
        vector<int>ans(2*n,-1);
        for(int i=(2*n)-1;i>=0;i--)
        {
            while(!s1.empty() && a[s1.top()]<=a[i])
            {
                s1.pop();
            }
            if(!s1.empty())ans[i]=a[s1.top()];
            s1.push(i);
        }
        vector<int>res(n,0);
        for(int i=0;i<n;i++)res[i]=ans[i];
        return res;
    }
};

//Interview Perspective
class Solution {
  public:
    vector<int> nextGreater(vector<int> &a) 
    {
        int n=a.size();
        vector<int>ans(n,-1);
        
        stack<int>s1;
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && a[s1.top()]<=a[i])
            {
                s1.pop();
            }
            if(!s1.empty())ans[i]=a[s1.top()];
            s1.push(i);
        }
        
        vector<int>is;
        is.push_back(a[0]);
        for(int i=1;i<n;i++)if(is.back()<a[i])is.push_back(a[i]);
        
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1)
            {
                auto in=upper_bound(is.begin(),is.end(),a[i])-is.begin();
                if(in!=is.size())
                {
                    ans[i]=is[in];   
                }
            }
        }
        return ans;
    }
};
