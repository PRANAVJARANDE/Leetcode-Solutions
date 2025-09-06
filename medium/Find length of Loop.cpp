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
    int lengthOfLoop(Node *head) 
    {
        map<Node*,int>m;
        Node* temp=head;
        int in=1;
        while(temp)
        {
            if(m[temp]!=0)return in-m[temp];
            m[temp]=in++;
            temp=temp->next;
        }
        return 0;
        
    }
};
