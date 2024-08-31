class Solution {
public:
    int generateKey(int n1, int n2, int n3) {
        int key=0;
        for(int i=0;i<4;i++)
        {
            int a1=n1%10;
            int a2=n2%10;
            int a3=n3%10;
            n1/=10;
            n2/=10;
            n3/=10;
            key+=pow(10,i)*min(a1,min(a2,a3));
        }
        return key;
    }
};
