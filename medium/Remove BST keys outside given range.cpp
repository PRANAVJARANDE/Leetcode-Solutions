/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    
    int helper(Node* root,int extra)
    {
        if(!root)return 0;
        int val=root->data;
        int right=helper(root->right,extra);
        root->data=extra+right;
        int left=helper(root->left,extra+right+val);
        return val+right+left;
    }
  
    void transformTree(Node *root) 
    {
        helper(root,0);
    }
};
