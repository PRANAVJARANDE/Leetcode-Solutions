class Solution 
{
public:

    Node* copyRandomList(Node* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        Node *nh=new Node(-1);
        Node *ptr=nh;
        Node *temp=head;

        vector<Node*> v1;
        vector<Node*> v2;
        while(temp!=NULL)
        {
            v1.push_back(temp);
            Node *n=new Node(temp->val);
            ptr->next=n;
            ptr=ptr->next;
            Node* tt=temp;
            temp=temp->next;
            tt->next=ptr;
        }
        Node* todel=nh;
        nh=nh->next;
        delete todel;

        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]->random==NULL)
            {
                v1[i]->next->random=NULL;
            }
            else
            {
                v1[i]->next->random=v1[i]->random->next;
            }
        }

        v1.push_back(NULL);
        for(int i=0;i<v1.size()-1;i++)
        {
            v1[i]->next=v1[i+1];
        }
        return nh;        
    }
};
