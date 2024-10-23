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

    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q1;
        vector<int> ls;
        q1.push(root);
        while(!q1.empty())
        {
            int sz=q1.size();
            int s=0;
            while(sz--)
            {
                auto temp=q1.front();
                q1.pop();
                s+= temp->val;
                if(temp->left)q1.push(temp->left);
                if(temp->right)q1.push(temp->right);
            }
            ls.push_back(s);
        }
        ls.push_back(0);
        int l=0;
        q1.push(root);
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                int s=0;
                auto temp=q1.front();
                q1.pop();
                if(temp->left)
                {
                    s+=temp->left->val;
                    q1.push(temp->left);
                }
                if(temp->right)
                {
                    s+=temp->right->val;
                    q1.push(temp->right);
                }
                if(temp->left)temp->left->val=ls[l+1]-s;
                if(temp->right)temp->right->val=ls[l+1]-s;
            }
            l++;
        }
        root->val=0;
        return root;
    }
};
