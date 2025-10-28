class SORTracker {
public:

    int in;
    struct Comp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const 
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;        
        }
    };

    struct Comp1 {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const 
        {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;        
        }
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> q1;
    priority_queue<pair<int, string>, vector<pair<int, string>>, Comp1> q2;

    SORTracker() {
        in=1;
    }
    
    void add(string s, int score) 
    {
        q1.push({score,s});
        if(q1.size()>in)
        {
            auto pr=q1.top();
            q1.pop();
            q2.push(pr);
        }
    }
    
    string get() 
    {
        auto ans=q1.top().second;
        in++;
        if(!q2.empty())
        {
            q1.push(q2.top());
            q2.pop();
        }
        return ans;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
