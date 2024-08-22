class SnapshotArray {
public:
    int sn;

    int lowerBound(int id, vector<vector<int>>& a) {
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid][0] < id) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l; // l is the index of the first element not less than id
    }

    vector<vector<vector<int>>> v1;
    SnapshotArray(int n) {
        sn=0;
        for(int i=0;i<n;i++)
        {
            vector<vector<int>> temp;
            temp.push_back({0,0});
            v1.push_back(temp);
        }
        
    }
    
    void set(int in, int val) {
        v1[in].push_back({sn,val});
    }
    
    int snap() {
        return sn++;
    }
    
    int get(int index, int snap_id) {
        int aid=lowerBound(snap_id+1,v1[index]);
        aid--;
        return v1[index][aid][1];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
