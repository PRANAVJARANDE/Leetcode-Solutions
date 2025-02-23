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
class Solution {
public:
    int n,in;
    map<int,int>m;
    TreeNode* helper(int par,vector<int>&a)
    {
        if(in>=n || m[a[in]]>=par)return NULL;
        int val=a[in];
        TreeNode* root=new TreeNode(val);
        in++;
        root->left=helper(m[val],a);
        root->right=helper(m[val],a);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& a, vector<int>& b) 
    {
        n=a.size();
        for(int i=0;i<n;i++)m[b[i]]=i;
        in=0;
        auto ans=helper(n,a);
        return ans;
    }
};
