/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    
    int in;
    map<Node*,int>m;
    void make(Node* root)
    {
        if(!root)return;
        m[root]=in++;
        make(root->left);
        make(root->right);
    }
    
    int helper(Node* root,int tk,vector<vector<int>>&dp)
    {
        if(!root)return 0;
        if(dp[m[root]][tk]!=-1)return dp[m[root]][tk];
        //ntake
        int op1=helper(root->left,1,dp)+helper(root->right,1,dp);
        //take
        int op2=0;
        if(tk==1)op2=(root->data)+helper(root->left,0,dp)+helper(root->right,0,dp);
        return dp[m[root]][tk]=max(op1,op2);
    }
  
  
    int getMaxSum(Node *root) {
        in=0;
        make(root);
        vector<vector<int>>dp(in,vector<int>(2,-1));
        int ans=helper(root,1,dp);
        return ans;
    }
};
