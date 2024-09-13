class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        int n=dist.size();
        for(int i=0;i<n;i++)
        {
            time.push_back((double)dist[i]/speed[i]);
        }
        sort(time.begin(),time.end());
        int ans=0,t=0;
        for(int i=0;i<n;i++)
        {
            if(time[i]-t<=0)
            {
                if(ans==0)
                    return 1;
                return ans;
            }
            t++;
            ans++;
        }
        return ans;
    }
};
