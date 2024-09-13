#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];  

    if(a[n-1]==1)
    {
        cout<<"NO"<<endl;
        return;
    }
    else cout<<"YES"<<endl;

    for(int i=n-1;i>=0;)
    {
        if(a[i]==0)
        {
            cout<<"0 ";
            i--;
        }
        else
        {
            int c=0;
            while(i>=0 && a[i]==1)
            {
                c++;
                i--;
            }
            int tp=c;
            c--;
            while(c--)cout<<"0 ";
            cout<<tp<<" ";
        }
    }

}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int t;cin >> t;
    while (t--) 
    {
        solve();
    }
    return 0;
}
