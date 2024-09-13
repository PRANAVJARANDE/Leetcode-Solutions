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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        int l=0;
        vector<int> store;
        while(!q1.empty())
        {
            auto k=q1.front();
            q1.pop();
            if(k!=NULL)
            {
                if(l%2==1)
                {
                    k->val=store.back();
                    store.pop_back();
                }
                if(k->left!=NULL)
                {
                    q1.push(k->left);
                    if(l%2==0)
                    store.push_back(k->left->val);
                }
                if(k->right!=NULL)
                {
                    q1.push(k->right);
                    if(l%2==0)
                    store.push_back(k->right->val);
                }
            }
            else if(!q1.empty())
            {
                l++;
                q1.push(NULL);
            }
        }
        return root;
    }
};
