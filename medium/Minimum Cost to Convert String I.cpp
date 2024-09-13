class Solution {
public:
    
void floydwarshall(vector<vector<int>> &gra)
{
    int n=gra.size();
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(gra[i][k]<INT_MAX && gra[k][j]<INT_MAX)
                {
                    gra[i][j]=min(gra[i][j], gra[i][k]+gra[k][j]);
                }
            }
        }
    }
}
  
    long long minimumCost(string src, string tar, vector<char>& org, vector<char>& cha, vector<int>& cost) 
    {
        vector<vector<int>>gra(26,vector<int>(26,INT_MAX));
        for(int i=0;i<org.size();i++)
        {
            gra[org[i]-'a'][cha[i]-'a']=min(cost[i],gra[org[i]-'a'][cha[i]-'a']);
        }
        
        floydwarshall(gra);
        
        long long ans=0;
        for(int i=0;i<src.size();i++)
        {
            if(src[i]!=tar[i])
            {
                if(gra[src[i]-'a'][tar[i]-'a']==INT_MAX)
                {
                    return -1;
                }
                else
                {
                    ans+=gra[src[i]-'a'][tar[i]-'a'];
                }
            }
        }
        return ans;
        
    }
};
