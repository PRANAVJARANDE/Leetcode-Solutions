#include<bits/stdc++.h>
using namespace std;

bool valid(string str)
{
    stack<char> s1;
    for(int i=0;i<str.size();i++)
    {
            if(str[i]=='{' || str[i]=='[' || str[i]=='(')
            {
                s1.push(str[i]);
            }
            else if(str[i]=='}' && s1.top()=='}')
            {
                s1.pop();
            }
            else if(str[i]==']' && s1.top()=='[')
            {
                s1.pop();
            }
            else if(str[i]=='}' && s1.top()=='{')
            {
                s1.pop();
            }
            else if(str[i]==')' && s1.top()=='(')
            {
                s1.pop();
            }
            else
            {
                return 0;
            }
    }

    return 1;
}
int main()
{
string str;
cin>>str;
cout<<valid(str);
return 0;
}
