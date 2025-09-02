/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) 
    {
        Node* temp=head;
        int sz=0;
        while(temp!=nullptr)
        {
            temp=temp->next;
            sz++;
        }
        
        int s1=k;
        int s2=sz-k+1;
        Node* t1;
        Node* t2;
        temp=head;
        int cs=0;
        while(temp!=nullptr)
        {
            cs++;
            if(cs==s1)t1=temp;
            if(cs==s2)t2=temp;
            temp=temp->next;
        }
        swap(t1->data,t2->data);
        return head;
        
    }
};
