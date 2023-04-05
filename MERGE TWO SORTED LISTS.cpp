#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertt(node *&head,int val)
{
    node *n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }

    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->next;
    }
}

node* mergee(node *&head1,node *&head2)
{
    node *ptr1=head1;
    node *ptr2=head2;
    node *n=new node(-1);
    while(ptr1!=NULL && ptr2!=NULL)
    {
        int a=ptr1->data;
        int b=ptr2->data;
        if(a>b)
        {
            insertt(n,b);
            ptr2=ptr2->next;
        }
        else
        {
            insertt(n,a);
            ptr1=ptr1->next;
        }
    }

    while(ptr1!=NULL)
    {
        insertt(n,ptr1->data);
        ptr1=ptr1->next;
    }

    while(ptr2!=NULL)
    {
        insertt(n,ptr2->data);
        ptr2=ptr2->next;
    }

    return n->next;
}






int main()
{
node *head1;
insertt(head1,1);
insertt(head1,2);
insertt(head1,3);
insertt(head1,4);
insertt(head1,5);

node *head2;
insertt(head2,1);
insertt(head2,3);
insertt(head2,5);
insertt(head2,7);
insertt(head2,9);

node *nh=mergee(head1,head2);
display(nh);

return 0;
}
