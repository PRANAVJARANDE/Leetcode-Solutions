/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution {
  public:
  
    pair<Node*,Node*> helper(Node*root)
    {   
        if(root==NULL)return {NULL,NULL};
        if(root->left==NULL && root->right==NULL)return {root,root};
        
        auto l=helper(root->left);
        auto r=helper(root->right);
        
        auto left=root;
        auto right=root;
        if(l.first!=NULL)left=l.first;
        if(r.second!=NULL)right=r.second;
        
        root->left=l.second;
        if(l.second)l.second->right=root;
        root->right=r.first;
        if(r.first)r.first->left=root;
        return {left,right};
    }
  
  
    Node* bToDLL(Node* root) {
        auto pr=helper(root);
        return pr.first;
    }
};
