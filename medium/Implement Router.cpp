class Router {
public:

    int queue_size;
    queue<vector<int>>q1;

    //optimize later
    map<vector<int>,bool>vis;

    map<int,vector<int>>dest_to_timestamp;
    map<int,int>time_stamp_start;

    Router(int memoryLimit) 
    {
        queue_size=memoryLimit;
    }

    vector<int> forwardPacket() 
    {
        if(q1.empty())return {};
        auto ans=q1.front();
        time_stamp_start[ans[1]]++;
        vis[ans]=0;
        q1.pop();
        return ans;
    }

    bool addPacket(int source, int destination, int timestamp) 
    {
        if(vis[{source,destination,timestamp}]==1)return 0;
        else 
        {
            if(q1.size()==queue_size)forwardPacket();
            dest_to_timestamp[destination].push_back(timestamp);
            vis[{source,destination,timestamp}]=1;
            q1.push({source,destination,timestamp});
            return 1;
        }
    }
    
    int getCount(int destination, int startTime, int endTime) 
    {
        int r=upper_bound(dest_to_timestamp[destination].begin(),dest_to_timestamp[destination].end(),endTime)-dest_to_timestamp[destination].begin();
        int l=lower_bound(dest_to_timestamp[destination].begin(),dest_to_timestamp[destination].end(),startTime)-dest_to_timestamp[destination].begin();
        l=max(l,time_stamp_start[destination]);
        return max(0,r-l);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
