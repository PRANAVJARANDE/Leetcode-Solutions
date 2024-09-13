class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) 
    {
        int n=a.size();
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>q1;
        q1.push({(double)a[0]/a[n-1],{0,n-1}});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][n-1]=1;
        while(!q1.empty())
        {
            int i=q1.top().second.first;
            int j=q1.top().second.second;
            q1.pop();
            k--;
            if(k==0)
            {
                return {a[i],a[j]};
            }
            if(i+1!=j)
            {
                if(vis[i+1][j]==0){
                    q1.push({(double)a[i+1]/a[j],{i+1,j}}); 
                    vis[i+1][j]=1; 
                }   
                if(vis[i][j-1]==0){
                    q1.push({(double)a[i]/a[j-1],{i,j-1}});
                    vis[i][j-1]=1;
                }            
            }
        }           
        return {a[0],a[n-1]}; 
    }
};
