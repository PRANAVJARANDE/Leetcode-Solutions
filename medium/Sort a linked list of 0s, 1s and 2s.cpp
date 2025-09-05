/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) 
    {
        map<int,int>m;
        Node* temp=head;
        while(temp)
        {
            m[temp->data]++;
            temp=temp->next;
        }
        temp=head;
        while(temp)
        {
            int u=(*m.begin()).first;
            m[u]--;
            if(m[u]==0)m.erase(u);
            temp->data=u;
            temp=temp->next;
        }
        return head;
        
    }
};
