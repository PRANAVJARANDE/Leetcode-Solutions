class Solution {
public:
    int numberOfChild(int n, int k) {
        int s=0;
        int dir=1;
        int i=0;
        while(1)
        {
            if(i==0)
            {
                dir=1;
            }
            if(i==n-1)
            {
                dir=-1;
            }
            if(s==k)
            {
                return i;
            }
            if(dir==1)i++;
            if(dir==-1)i--;
            s++;
        }
    }
};
