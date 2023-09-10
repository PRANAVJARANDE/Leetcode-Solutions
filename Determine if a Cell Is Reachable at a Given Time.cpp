class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
            if(sx==fx && sy==fy)
            {
                if(t==1)
                {
                        return 0;
                }
            }
                    
            int m=min(abs(sx-fx),abs(sy-fy));
            int k1=abs(sx-fx)-m;
            int k2=abs(sy-fy)-m;
            int tot=m+k1+k2;
            if(tot<=t)
            {
                    return 1;
            }
            return 0;
        
    }
};
