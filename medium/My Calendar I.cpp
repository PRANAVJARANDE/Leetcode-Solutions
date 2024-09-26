class MyCalendar {
public:
    int smin;
    int emax;
    set<pair<int,int>>s1;
    MyCalendar() {
        smin=INT_MAX;
        emax=INT_MIN;
    }

    bool book(int s, int e) {
        if(e<=smin || s>=emax)
        {
            emax=max(emax,e);
            smin=min(smin,s);
            s1.insert({s,e});
            return 1;
        }
        
        auto ub=s1.lower_bound({s,e});
        if (ub != s1.begin()) {
            --ub;
            if (ub->second > s) 
            {
                return 0;
            }
        }
        ub=s1.lower_bound({s, e});
        if(ub!=s1.end() && ub->first<e)
        {
            return false;
        }
        s1.insert({s, e});
        emax = max(emax, e);
        smin = min(smin, s);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
