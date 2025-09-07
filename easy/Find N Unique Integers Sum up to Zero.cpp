class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>a(n,0);
        int in=1;
        for(int i=1;i<n;i+=2)
        {
            a[i]=in;
            a[i-1]=-in;
            in++;
        }
        return a;
    }
};
