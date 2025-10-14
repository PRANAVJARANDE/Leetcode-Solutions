/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution 
{
  public:
  
    int helper(Node* root,int l,int r)
    {
        if(!root)return 0;
        int v=root->data;
        if(v<l)return helper(root->right,l,r);
        if(r<v)return helper(root->left,l,r);
        int left=helper(root->left,l,r);
        int right=helper(root->right,l,r);
        return left+right+v;
    }
    
    int nodeSum(Node* root, int l, int r) 
    {
        return helper(root,l,r);
    }
};
