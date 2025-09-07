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
    Node* mergeKLists(vector<Node*>& a) 
    {
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>q1;
        for(auto x:a)if(x)q1.push({x->data,x});
        Node* temp=NULL;
        Node* head=NULL;
        while(!q1.empty())
        {
            auto in=q1.top().second;
            q1.pop();
            if(temp==NULL)
            {
                temp=in;
                head=in;
            }
            else
            {
                temp->next=in;
                temp=temp->next;
            }
            if(in->next)q1.push({in->next->data,in->next});
        }
        return head;
        
    }
};
