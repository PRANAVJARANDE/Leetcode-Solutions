class MyCalendarTwo {
public:
    map<int,int> m;
    MyCalendarTwo() {
        
    }
    bool book(int s, int e) {
        int ev=0;
        m[s]++;
        m[e]--;
        for(auto x: m)
        {
            ev+=x.second;
            if(ev>=3)
            {
                m[s]--;
                m[e]++;
                return 0;
            }
        }   
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
