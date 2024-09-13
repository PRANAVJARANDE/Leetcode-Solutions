#include<bits/stdc++.h>
using namespace std;
int ris(char ch)
{
    int a;
    switch(ch)
    {
        case 'I': a=1;
        break;
        case 'V': a=5;
        break;
        case 'X': a=10;
        break;
        case 'L': a=50;
        break;
        case 'C': a=100;
        break;
        case 'D': a=500;
        break;
        case 'M': a=1000;
        break;
    }
    return a;
}




int con(string str)
{
    int ans=0;
    for(int i=str.size()-1;i>=0;)
    {
        char ch1=str[i];
        char ch2=str[i-1];

        if(ris(ch1)>ris(ch2))
        {
            int t=ris(ch1)-ris(ch2);
            ans=ans+t;
            i=i-2;
        }
        else
        {
            ans=ans+ris(ch1);
            i--;
        }
    }


    return ans;
}

int main()
{
string str;
cin>>str;
cout<<con(str);

return 0;
}
