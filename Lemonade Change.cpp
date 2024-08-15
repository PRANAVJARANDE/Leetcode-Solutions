class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a5=0,a10=0;
        for(int x:bills)
        {
            if(x==5)a5++;
            else if(x==10)
            {
                a10++;
                a5--;
                if(a5<0)return 0;
            }
            else
            {
                if(a10==0)
                {
                    a5-=3;
                    if(a5<0)return 0;
                }
                else
                {
                    a10--;
                    a5--;
                    if(a5<0)return 0;
                }

            }
            
        }
        return 1;
    }
};
