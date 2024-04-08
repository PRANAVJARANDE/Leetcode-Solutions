class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sa) 
    {
        int z=0,o=0,n=sa.size();
        for(int i=0;i<n;i++)
        {
            if(st[i]==0)z++;
            else o++;
        }

        for(int i=0;i<n;i++)
        {
            if(sa[i]==0)
            {
                if(z==0)
                {
                    return n-i;
                }
                z--;
            }
            else
            {
                if(o==0)
                {
                    return n-i;
                }
                o--;
            }
            
        }
        return 0;
        
        
    }
};
