class LFUCache {
public:

    int in;
    int sz;
    
    set<pair<pair<int,int>,int>>s1;
    map<int,int>key_used;
    map<int,int>key_in;
    map<int,int>key_value;

    LFUCache(int cap) 
    {
        sz=cap;
        in=0;
    }
    
    int get(int key) 
    {
        if(key_in.find(key)==key_in.end())return -1;
        int res=key_value[key];
        s1.erase({{key_used[key],key_in[key]},key});
        key_used[key]++;
        key_in[key]=in;
        in++;
        s1.insert({{key_used[key],key_in[key]},key});
        return res;
    }
    
    void put(int key, int val) 
    {
        //already existing key
        if(key_used.find(key)!=key_used.end())
        {
            s1.erase({{key_used[key],key_in[key]},key});
            key_used[key]++;
            key_in[key]=in;
            in++;
            key_value[key]=val;
            s1.insert({{key_used[key],key_in[key]},key});
            return;
        }
        //capacity not full
        if(s1.size()<sz)
        {
            key_used[key]++;
            key_in[key]=in;
            in++;
            key_value[key]=val;
            s1.insert({{key_used[key],key_in[key]},key});
            return;
        }
        //capacity full and remove someone
        auto fs=*s1.begin();
        int puse=fs.first.first;
        int pin=fs.first.second;
        int pkey=fs.second;
        key_used.erase(pkey);
        key_in.erase(pkey);
        s1.erase(s1.begin());

        key_used[key]++;
        key_in[key]=in;
        in++;
        key_value[key]=val;
        s1.insert({{key_used[key],key_in[key]},key});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
