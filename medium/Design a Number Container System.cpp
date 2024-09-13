class NumberContainers {
public:

    unordered_map<int,set<int>> m;
    unordered_map<int,int> ind;

    NumberContainers() {
        
    }
    
    void change(int in, int num) {
        if(ind.find(in)!=ind.end())
        {
            int h=ind[in];
            m[h].erase(in);
        }
        ind[in]=num;
        m[num].insert(in);
    }
    
    int find(int n) {
        if(m[n].size()==0)
        {
            return -1;
        }
        return *m[n].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
