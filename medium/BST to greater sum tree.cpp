/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    Node* helper(Node* root,int l,int r)
    {
        if(!root)return NULL;
        int val=root->data;
        
        if(r<val)
        {
            return helper(root->left,l,r);
        }
        else if(val<l)
        {
            return helper(root->right,l,r);
        }
        else
        {
            root->left=helper(root->left,l,r);
            root->right=helper(root->right,l,r);
            return root;
        }
    }
  
    Node* removekeys(Node* root, int l, int r) 
    {
        return helper(root,l,r);
    }
};
