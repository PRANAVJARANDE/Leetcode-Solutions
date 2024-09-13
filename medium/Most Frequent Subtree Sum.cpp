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

    int mfs(TreeNode* root,unordered_map<int,int> &m)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lm=mfs(root->left,m);
        int rm=mfs(root->right,m);
        m[lm+rm+root->val]++;
        return lm+rm+root->val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        unordered_map<int,int> m;
        mfs(root,m);
        priority_queue<pair<int,int>>q1;
        for(auto x: m)
        {
            q1.push({x.second,x.first});
        }
        int a=q1.top().first;
        vector<int> ans;
        while(!q1.empty() && q1.top().first==a)
        {
            ans.push_back(q1.top().second);
            q1.pop();
        }
        return ans;
    }
};
