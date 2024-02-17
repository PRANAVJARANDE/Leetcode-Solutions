class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) 
    {
        int n=h.size();
        priority_queue<int,vector<int>,greater<int>>q1;
        for(int i=0;i<n-1;i++)
        {
            int d=h[i+1]-h[i];
            if(d>0)
            {
                if(q1.size()<l)
                {
                    q1.push(d);
                }
                else
                {
                    if(!q1.empty() && q1.top()<d)
                    {
                        b-=q1.top();
                        q1.pop();
                        q1.push(d);
                    }
                    else
                    {
                        b-=d;
                    }

                    if(b<0)
                    {
                        return i;
                    }
                }
            }
        }
        return n-1;

    }
};
