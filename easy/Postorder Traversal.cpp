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
    
    void helper(Node* root,vector<int>&ans)
    {
        if(!root)return;
        helper(root->left,ans);
        helper(root->right,ans);
        ans.push_back(root->data);
    }
  
  
    vector<int> postOrder(Node* root) {
        vector<int>ans;
        helper(root,ans);
        return ans;
    }
};
