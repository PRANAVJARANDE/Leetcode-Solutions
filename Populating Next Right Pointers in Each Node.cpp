class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
        {
            return root;
        }
        queue<Node*> q1;
        q1.push(root);
        q1.push(NULL);

        while(!q1.empty())
        {
            Node* k=q1.front();
            q1.pop();
            
            if(k!=NULL)
            {
                k->next=q1.front();
                if(k->left!=NULL)
                {
                    q1.push(k->left);
                }
                if(k->right!=NULL)
                {
                    q1.push(k->right);
                }
            }
            else if(!q1.empty())
            {
                q1.push(NULL);
            }
        }
        return root;
    }
};
