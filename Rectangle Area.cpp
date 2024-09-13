class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int a1=abs(ax2-ax1)*abs(ay2-ay1);
        int a2=abs(bx2-bx1)*abs(by2-by1);

       if(bx1>ax2 || by1>ay2 || ax1>bx2 || ay1>by2)
       {
           return a1+a2;
       }
        int xc2=min(ax2,bx2);
        int yc2=min(ay2,by2);
        int xc1=max(ax1,bx1);
        int yc1=max(ay1,by1);

        int ca=(xc2-xc1)*(yc2-yc1);
        return a1+a2-ca;
    }
};
