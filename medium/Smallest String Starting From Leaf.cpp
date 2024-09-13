class Solution {
public:

    string ans="";
    void helper(TreeNode* root,string t)
    {
        if(root==NULL)
        {
            return ;
        }
        char ch=root->val + 'a';
        t=ch+t;
        if(root->left==NULL && root->right==NULL)
        {
            if(ans=="" || t<ans)
            {
                ans=t;
            }
            return;
        }
        helper(root->left,t);
        helper(root->right,t);
    }



    string smallestFromLeaf(TreeNode* root)
    {
        string a="";
        helper(root,a);
        return ans;
    }

};
