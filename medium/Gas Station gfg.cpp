class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) 
    {
        int st=0;
        int s=0;
        int cs=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            s+=gas[i]-cost[i];
            cs+=gas[i]-cost[i];
            if(cs<0)
            {
                cs=0;
                st=i+1;
            }
        }
        if(s<0)return -1;
        return st;
    }
};
