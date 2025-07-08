class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(),events.end());
        int events_attended=0;
        priority_queue<int,vector<int>,greater<int>>end_dates;

        int in=0;
        int n=events.size();
        for(int day=1;day<=1e5;day++)
        {
            while(in<n && events[in][0]<=day)
            {
                end_dates.push(events[in][1]);
                in++;
            }
            while(!end_dates.empty() && end_dates.top()<day)
            {
                end_dates.pop();
            }
            if(!end_dates.empty())
            {
                events_attended++;
                end_dates.pop();
            }
        }
        return events_attended;  
    }
};
