#include<bits/stdc++.h>
using namespace std;

int squareroot(int x)
{
    if(x==0)
    {
        return 0;
    }
    int l=0;
    int r=x;

    while(l<r)
    {
        int mid=(l+r)/2;
        if(mid*mid==x)
        {
            return mid;
        }
        else if(mid<=(x/mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    return l;




}





int main()
{
cout<<squareroot(4);







return 0;
}
