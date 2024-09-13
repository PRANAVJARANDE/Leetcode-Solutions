#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

int maxpro=0;
int minbuy=INT_MAX;

for(int i=0;i<n;i++)
{
    minbuy=min(minbuy,arr[i]);
    maxpro=max(maxpro,arr[i]-minbuy);
}

cout<<maxpro;


return 0;
}
