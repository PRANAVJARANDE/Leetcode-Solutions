/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) 
    {
        while(head)
        {
            swap(head->next,head->prev);
            if(!head->prev)break;
            head=head->prev;
        }
        return head;
        
    }
};
