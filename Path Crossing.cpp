class Solution {
public:
    bool isPathCrossing(string path) 
    {
        set<pair<int,int>> s1;
        int dx=0,dy=0;
        s1.insert({dx,dy});
        for(char x: path)
        {
            if(x=='N')
            {
                dy++;
            }
            else if(x=='S')
            {
                dy--;
            }
            else if(x=='E')
            {
                dx++;
            }
            else
            {
                dx--;
            }
            if(s1.find({dx,dy})!=s1.end())
            {
                return 1;
            }
            s1.insert({dx,dy});
        }
        return 0;
    }
};
