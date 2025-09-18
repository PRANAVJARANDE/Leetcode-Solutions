class TaskManager {
public:

    set<vector<int>>s1;
    map<int,int>task_to_user;
    map<int,int>task_to_priority;
    TaskManager(vector<vector<int>>& tasks) 
    {
        for(auto x:tasks)
        {
            task_to_priority[x[1]]=x[2];
            task_to_user[x[1]]=x[0];
            s1.insert({x[2],x[1],x[0]});
        }
    }
    
    void add(int userId, int taskId, int priority) 
    {
        task_to_user[taskId]=userId;
        task_to_priority[taskId]=priority;
        s1.insert({priority,taskId,userId});
    }

    void rmv(int taskId) 
    {
        s1.erase(s1.find({task_to_priority[taskId],taskId,task_to_user[taskId]}));
        task_to_user.erase(taskId);
        task_to_priority.erase(taskId);
    }
    
    void edit(int taskId, int newPriority) 
    {
        int u=task_to_user[taskId];
        int p=task_to_priority[taskId];
        rmv(taskId);
        add(u,taskId,newPriority);
    }
    
    int execTop() 
    {
        if(s1.empty())return -1;
        auto tp=*s1.rbegin();
        rmv(tp[1]);
        return tp[2];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
