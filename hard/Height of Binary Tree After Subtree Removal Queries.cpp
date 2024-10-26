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
    map<int,int> m;
    int helper(TreeNode* root)
    {
        if(root==NULL)return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        m[root->val]=max(l,r);
        return max(l,r)+1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        helper(root);
        queue<TreeNode*> q1;
        q1.push(root);
        int l=0;
        map<int,int> ans;
        while(!q1.empty())
        { 
            int sz=q1.size();
            if(sz==1)
            {
                auto q=q1.front();
                q1.pop();
                ans[q->val]=l-1;
                l++;
                if(q->left)q1.push(q->left);
                if(q->right)q1.push(q->right);
                continue;
            }
            int m1=0,m2=0;
            for(int i=0;i<sz;i++)
            {   
                auto q=q1.front();
                if(m[q->val]>m[m1])
                {
                    m2=m1;
                    m1=q->val;
                }
                else if(m[q->val] > m[m2])
                {
                    m2=q->val;
                }
                q1.pop();
                q1.push(q);
            }
            while(sz--)
            {
                auto q=q1.front();
                q1.pop();
                if(q->val==m1)ans[q->val]=l+m[m2];
                else ans[q->val]=l+m[m1];
                if(q->left)q1.push(q->left);
                if(q->right)q1.push(q->right);
            }
            l++;
        }

        for(auto &q:queries)
        {
            q=ans[q];
        }
        return queries;
    }
};
