/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) 
    {
        //if(head==nullptr)return head;
        map<Node*,bool>vis;
        Node* temp=head;
        vis[temp]=1;
        while(temp->next!=nullptr && vis[temp->next]==0)
        {
            vis[temp->next]=1;
            temp=temp->next;
        }
        temp->next=nullptr;
    }
};
