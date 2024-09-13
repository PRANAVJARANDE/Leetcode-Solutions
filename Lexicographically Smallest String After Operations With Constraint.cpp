class Solution {
public:
    string getSmallestString(string s, int k) 
    {
        int n=s.size();
        for(int i=0;i<n && k>0 ;i++)
        {
            for(int j=0;j<26;j++)
            {
                char ch=j+'a';
                int dis=abs(ch-s[i]);
                dis=min(dis,26-dis);
                if(dis<=k)
                {
                    k-=dis;
                    s[i]=ch;
                    break;
                }
            }
        }
        return s;
        
    }
};
