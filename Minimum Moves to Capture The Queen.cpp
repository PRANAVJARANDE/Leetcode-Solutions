class Solution {
public:
    
    
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) 
    {
        
        
        
        int i=c,j=d;
        
        while(i<=8 && j<=8)
        {
            i++;
            j++;
            if(i==a && j==b)
            {
                break;
            }
            if(i==e && j==f)
            {
                return 1;
            }
        }
        
        i=c,j=d;
        while(i<=8 && j>=1)
        {
            i++;
            j--;
            if(i==a && j==b)
            {
                break;
            }
            if(i==e && j==f)
            {
                return 1;
            }
        }
        
        i=c,j=d;
        while(i>=1 && j>=1)
        {
            i--;
            j--;
            if(i==a && j==b)
            {
                break;
            }
            if(i==e && j==f)
            {
                return 1;
            }
        }
        
        i=c,j=d;
        while(i>=1 && j<=8)
        {
            i--;
            j++;
            if(i==a && j==b)
            {
                break;
            }
            if(i==e && j==f)
            {
                return 1;
            }
        }
        
        i=a,j=b;
        while(i<=8)
        {
            i++;
            if(i==c && j==d)
            {
                break;
            }
            if(i==e && j==f)
            {
                return 1;
            }
        }
        
        i=a,j=b;
        while(i>=1)
        {
            i--;
            if(i==c && j==d)
            {
                break;
            }
            if(i==e && j==f)
            {
                return 1;
            }
        }
        
        i=a,j=b;
        while(j>=1)
        {
            j--;
            if(i==c && j==d)
            {
                break;
            }
            if(i==e && j==f)
            {
                return 1;
            }
        }
        
        i=a,j=b;
        while(j<=8)
        {
            j++;
            if(i==c && j==d)
            {
                break;
            }
            if(i==e && j==f)
            {
                return 1;
            }
        }
        
        
        return 2;
    }
};
