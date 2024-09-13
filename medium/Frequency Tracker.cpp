class FrequencyTracker {
public:

    unordered_map<int,int> m;
    unordered_map<int,int> freq;

    FrequencyTracker() {
        
    }
    
    void add(int n) {
        m[n]++;
        if(m[n]!=1)
        {
            freq[m[n]-1]--;
        }
        freq[m[n]]++;
    }
    
    void deleteOne(int n) {
        if(m[n]!=0)
        {
            freq[m[n]]--;
            m[n]--;
            freq[m[n]]++;
        }
    }
    
    bool hasFrequency(int f) {
        if(freq[f]!=0)
        {
            return 1;
        }
        return 0;
    }
};
