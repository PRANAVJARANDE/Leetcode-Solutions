class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        map<int,int>m;
        for(int x: a)m[((x%k)+k)%k]++;
        if(m[0]%2)return 0;
        for(int x:a)
        {
            int req=(k-(((x%k)+k)%k))%k;
            if(m[req])m[req]--;
            else
            {
                return 0;
            }
        }
        return 1;
    }
};
