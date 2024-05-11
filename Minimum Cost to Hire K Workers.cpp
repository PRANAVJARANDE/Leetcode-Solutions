class Solution {
public:

    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) 
    {
        int n=q.size();
        vector<pair<double,pair<int,int>>>a;
        for(int i=0;i<n;i++)
        {   
            a.push_back({(double)w[i]/q[i],{q[i],w[i]}}); 
        }
        sort(a.begin(),a.end());
        priority_queue<int> q1;
        int sum=0;
        double maxi=0.0;
        for(int i=0;i<k;i++)
        {
            q1.push(a[i].second.first);
            maxi=max(maxi,a[i].first);
            sum+=a[i].second.first;
        }
        double ans=sum*maxi;
        for(int i=k;i<n;i++)
        {
            maxi=max(maxi,a[i].first);
            sum-=q1.top();
            q1.pop();
            q1.push(a[i].second.first);
            sum+=a[i].second.first;
            ans=min(ans,maxi*sum);
        }
        return ans;
    }
};
