class Solution {
public:
    double maxAmount(string ic,vector<vector<string>>&p1,vector<double>&r1,vector<vector<string>>&p2,vector<double>&r2) {
        
        map<string,double>m;
        m[ic]=1.0;
        queue<pair<double,string>>q1;
        q1.push({1.0,ic});
        
        while(!q1.empty())
        {
            auto fr=q1.front();
            q1.pop();
            string cr=fr.second;
            double val=fr.first;
            
            for(int i=0;i<p1.size();i++)
            {
                if(p1[i][0]==cr)
                {
                    string ncr=p1[i][1];
                    double nval=r1[i]*val;
                    if(m[ncr]<nval)
                    {
                        m[ncr]=nval;
                        q1.push({nval,ncr});
                    }
                }
                
                if(p1[i][1]==cr)
                {
                    string ncr=p1[i][0];
                    double nval=val/r1[i];
                    if(m[ncr]<nval)
                    {
                        m[ncr]=nval;
                        q1.push({nval,ncr});
                    }
                }
            }
        }
        
        for(auto x: m)
        {
            q1.push({x.second,x.first});
        }
        while(!q1.empty())
        {
            auto fr=q1.front();
            q1.pop();
            string cr=fr.second;
            double val=fr.first;
            
            for(int i=0;i<p2.size();i++)
            {
                if(p2[i][0]==cr)
                {
                    string ncr=p2[i][1];
                    double nval=r2[i]*val;
                    if(m[ncr]<nval)
                    {
                        m[ncr]=nval;
                        q1.push({nval,ncr});
                    }
                }
                
                if(p2[i][1]==cr)
                {
                    string ncr=p2[i][0];
                    double nval=val/r2[i];
                    if(m[ncr]<nval)
                    {
                        m[ncr]=nval;
                        q1.push({nval,ncr});
                    }
                }
            }
        }
        
        double ans=m[ic];
        return ans;
    }
};
