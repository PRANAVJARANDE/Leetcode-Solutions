#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"ENTER NUMBER OF STRINGS-";
    cin>>n;
    string arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    string ans="";

    for(int i=0;;i++)
    {
        int c=0;

        for(int j=0;j<n;j++)
        {
            if(arr[0][i]==arr[j][i])
            {
                c++;
            }
        }
        if(c==n)
        {
           ans=ans+arr[0][i];
        }
        else
        {
            break;
        }
    }

    cout<<ans<<endl;
  return 0;
}
