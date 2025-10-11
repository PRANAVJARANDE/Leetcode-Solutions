/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    map<Node*,int>m;
    int maxi;
    int helper(Node* root)
    {
        if(!root)return 0;
        maxi=max(maxi,root->data);
        int left=helper(root->left);
        int right=helper(root->right);
        return m[root]=max(0,(root->data)+max(left,right));
    }
    
    int getans(Node* root,int extra)
    {
        if(!root)return 0;
        int ans=max(m[root],extra+(root->data));
        int op1=getans(root->left,(root->data)+max(extra,m[root->right]));
        int op2=getans(root->right,(root->data)+max(extra,m[root->left]));
        return max(ans,max(op1,op2));
    }
  
  
    int findMaxSum(Node *root) 
    {
        maxi=INT_MIN;
        helper(root);
        if(maxi<=0)return maxi;
        return getans(root,0);
    }
};
