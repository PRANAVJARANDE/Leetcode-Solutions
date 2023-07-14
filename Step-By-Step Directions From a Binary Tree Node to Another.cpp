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

    bool searchh(TreeNode* root,string &ans,int e)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->val==e)
        {
            return 1;
        }
        
        if(searchh(root->left,ans,e))
        {
            ans+="L";
            return 1;
        }
        if(searchh(root->right,ans,e))
        {
            ans+="R";
            return 1;
        }
        return 0;
    }

    
    string getDirections(TreeNode* root, int s, int e) 
    {
        string ss="",ee="";
        searchh(root,ss,s);
        searchh(root,ee,e);

        while(!ss.empty() && !ee.empty() && ss.back()==ee.back())
        {
            ss.pop_back();
            ee.pop_back();
        }
        reverse(ee.begin(),ee.end());
        return string(ss.size(),'U')+ee;
    }
};
