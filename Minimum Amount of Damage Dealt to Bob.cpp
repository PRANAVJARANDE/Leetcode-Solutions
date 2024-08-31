class Solution {
public:
    
    long long minDamage(int power, vector<int>& d, vector<int>& h) {
        int n=d.size();
        vector<int> v1(n);
        long long s=0;
        for(int i=0;i<n;i++)
        {
            v1[i]=i;
            s+=d[i];
        }
        sort(v1.begin(), v1.end() , [&](int i,int j){
            int gh1=static_cast<int>(ceil(static_cast<double>(h[i])/power));
            int gh2=static_cast<int>(ceil(static_cast<double>(h[j])/power));
            double eff1=(double)d[i]/gh1;
            double eff2=(double)d[j]/gh2;
            if(eff1==eff2)return d[i]>d[j];
            return eff1>eff2;
        });
        
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            int ghav=static_cast<int>(ceil(static_cast<double>(h[v1[i]])/power));
            ans+=ghav*s;
            s-=d[v1[i]];
        }
        return ans;
    }
};
