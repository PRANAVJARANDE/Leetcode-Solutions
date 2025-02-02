class Solution {
public:
    int maxDistance(string s, int kk) {
        map<char,int>m;
        int ans=0;
        for(auto x:s)
        {
            m[x]++;
            
            int k=kk;
            int t1=min(m['N'],m['S']);
            int t2=max(m['N'],m['S']);
            int t3=min(m['E'],m['W']);
            int t4=max(m['E'],m['W']);
            
            int ts=min(k,t1);
            t2+=ts;
            k-=ts;
            t1-=ts;
            

            ts=min(k,t3);
            t4+=ts;
            t3-=ts;
            k-=ts;
            
            int dis=t2+t4-t3-t1;
            //cout<<dis<<" ";
            ans=max(ans,dis);
        }
        
        cout<<endl;
        return ans;
        
        
        
    }
};
