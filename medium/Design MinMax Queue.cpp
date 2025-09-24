class SpecialQueue {

  public:
    
    queue<int>q1;
    deque<int>mini,maxi;
    
    void enqueue(int x) 
    {
        q1.push(x);
        while(!mini.empty() && mini.back()>x)mini.pop_back();
        mini.push_back(x);
        while(!maxi.empty() && maxi.back()<x)maxi.pop_back();
        maxi.push_back(x);
    }

    void dequeue() 
    {
        if(q1.empty())return;
        auto in=q1.front();
        q1.pop();
        if(maxi.front()==in)maxi.pop_front();
        if(mini.front()==in)mini.pop_front();
    }

    int getFront() 
    {
        if(q1.empty())return -1;
        return q1.front();
    }

    int getMin() 
    {
        if(q1.empty())return -1;
        return mini.front();
    }

    int getMax() 
    {
        if(q1.empty())return -1;
        return maxi.front();
    }
};
