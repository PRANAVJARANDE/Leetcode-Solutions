class LRUCache {
public:
    int n;
    set<pair<int,int>> s1;
    unordered_map<int,pair<int,int>> m;
    int t;
    LRUCache(int capacity) {
        n=capacity;
        t=0;
    }
    
    int get(int key) 
    {
        if(m.find(key)==m.end())
            return -1;
        
        int ct=m[key].second;
        t++;
        s1.erase(s1.find({ct,key}));
        s1.insert({t,key});
        m[key]={m[key].first,t};
        return m[key].first;        
    }
    
    void put(int key, int val) 
    {
        if(m.find(key)==m.end())
        {
        if(s1.size()==n)
        {
            pair<int,int>p1=*s1.begin();
            s1.erase(s1.begin());
            m.erase(p1.second);
        }
        t++;
        m[key]={val,t};
        s1.insert({t,key});
        }
        else
        {
            pair<int,int> p1=m[key];
            s1.erase({p1.second,key});
            t++;
            s1.insert({t,key});
            m[key]={val,t};
        }
        
    }
}; 
