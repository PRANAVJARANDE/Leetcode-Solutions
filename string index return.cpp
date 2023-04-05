#include<bits/stdc++.h>
using namespace std;

int findd(string str,string f)
{
    int m=str.size();
    int n=f.size();

    for(int i=0;i<=m-n;i++)
    {
        int k=0;
        for(int j=0;j<n;j++)
        {
            if(str[i+j]==f[j])
            {
                k++;
            }
            else
            {
                k=0;
                break;
            }
        }

            if(k==n)
            {
                return i;
            }

    }

    return -1;
}







int main()
{
string str;
cin>>str;

string f;
cin>>f;

cout<<findd(str,f);


return 0;
}
