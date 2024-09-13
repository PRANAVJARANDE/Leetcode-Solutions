class FreqStack {
public:

    unordered_map<int,int> freq;
    priority_queue<pair<int,pair<int,int>>> q1;
    int id;
    FreqStack() 
    {
        id=0;
    }
    
    void push(int val) 
    {
        freq[val]++;
        q1.push({freq[val],{id,val}});
        id++;
    }
    
    int pop() 
    {
        int t=q1.top().second.second;
        freq[t]--;
        q1.pop();
        return t;
    }
};
