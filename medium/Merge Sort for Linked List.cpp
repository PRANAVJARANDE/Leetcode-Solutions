/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
  
  
    Node* divide(Node* head)
    {
        int sz=0;
        Node* temp=head;
        while(temp)
        {
            temp=temp->next;
            sz++;
        }
        
        if(sz<=1)return head;
        
        int mid=sz/2;
        temp=head;
        while(--mid)temp=temp->next;
        Node* right=divide(temp->next);
        temp->next=NULL;
        Node* left=divide(head);
        
        
        
        //merge both
        Node* t1=left;
        Node* t2=right;
        Node* res=NULL;
        Node* nh=NULL;
        while(t1 && t2)
        {
            if((t1->data)>(t2->data))
            {
                if(res==NULL)
                {
                    res=t2;
                    nh=t2;
                }
                else 
                {
                    res->next=new Node(t2->data);
                    res=res->next;
                }
                t2=t2->next;
            }
            else 
            {
                if(res==NULL)
                {
                    res=t1;
                    nh=t1;
                }
                else 
                {
                    res->next=new Node(t1->data);
                    res=res->next;
                }
                t1=t1->next;
            }
        }
        
        
        while(t1)
        {
            if(res==NULL)
            {
                res=t1;
                nh=t1;
            }
            else 
            {
                res->next=new Node(t1->data);
                res=res->next;
            }
            t1=t1->next;
        }
        
        while(t2)
        {
            if(res==NULL)
            {
                res=t2;
                nh=t2;
            }
            else 
            {
                res->next=new Node(t2->data);
                res=res->next;
            }
            t2=t2->next;
        }
        return nh;
    }
  
  
  
  
    Node* mergeSort(Node* head) 
    {
        return divide(head);
    }
};
