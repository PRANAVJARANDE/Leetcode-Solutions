/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    set<int>vis;
    void build(TreeNode* root,int in)
    {
        if(root==NULL)return;
        root->val=in;
        vis.insert(in);
        build(root->left,2*in+1);
        build(root->right,2*in+2);
    }

    FindElements(TreeNode* root) 
    {
        build(root,0);
    }
    
    bool find(int t) 
    {
        if(vis.find(t)!=vis.end())return 1;
        return 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
