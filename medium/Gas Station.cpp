class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int needed=0;
        int cg=0,s=0,n=gas.size();
        for(int i=0;i<n;i++)
        {
            cg=cg+gas[i]-cost[i];
            if(cg<0)
            {
                needed=needed+abs(cg);
                cg=0;
                s=i+1;
            }
        }    
        return needed>cg ? -1:s;
    }
};
