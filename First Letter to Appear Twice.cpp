class Solution {
public:
    char repeatedCharacter(string a) 
    {
        vector<int>v1(26,-1);
        for(int i=0;i<a.size();i++)
        {
            int z=a[i]-'a';
            v1[z]++;
            if(v1[z]==1)
            {
                return a[i];
            }
        }
        return '0';
    }
};
