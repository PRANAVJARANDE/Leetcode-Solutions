class Solution {
public:

    int scheduleCourse(vector<vector<int>>& a)
    {
        int n=a.size();
        for(int i=0;i<n;i++)swap(a[i][0],a[i][1]);
        sort(a.begin(),a.end());
        priority_queue<int>q1;
        int ans=0;
        int d=0;
        for(auto x:a)
        {
            int ls=x[0];
            int dur=x[1];
            if(d+dur<=ls)
            {
                d+=dur;
                q1.push(dur);
            }
            else if(!q1.empty() && q1.top()>dur)
            {
                d+=dur-q1.top();
                q1.pop();
                q1.push(dur);
            } 
        }
        return q1.size();
    }
};
