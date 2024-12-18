class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {
        int n=a.size();
        stack<int> s1;
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && s1.top()>a[i])
            {
                s1.pop();
            }
            int nm=0;
            if(!s1.empty())nm=s1.top();
            s1.push(a[i]);
            a[i]-=nm;
        }
        return a;
    }
};
