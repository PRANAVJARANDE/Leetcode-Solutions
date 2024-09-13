class AllOne {
public:

    unordered_map<string,int> m;
    set<pair<int,string>> s1;

    AllOne() {

    }
    
    void inc(string key) {

        s1.erase({m[key],key});
        m[key]++;
        s1.insert({m[key],key});
    }
    
    void dec(string key) {
        s1.erase({m[key],key});
        m[key]--;
        if(m[key]==0)
        {
            m.erase(key);
        }
        else
        {
            s1.insert({m[key],key});
        }
    }
    
    string getMaxKey() {
        if(s1.size()!=0)
        {
            return s1.rbegin()->second;
        }
        return "";
    }
    
    string getMinKey() {
        if(s1.size()!=0)
        {
            return s1.begin()->second;
        }
        return "";
    }
};
