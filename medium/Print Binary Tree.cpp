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

    void filler(TreeNode* root,vector<vector<string>> &arr,int i,int j,int h)
    {
        if(root==NULL)
        {
            return;
        }
        int mid=(i+j)/2;
        arr[h][mid]=to_string(root->val);
        filler(root->left,arr,i,mid-1,h+1);
        filler(root->right,arr,mid+1,j,h+1);
    }

    int heightt(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return 1+max(heightt(root->left),heightt(root->right));
    }


public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h=heightt(root);
        int c=pow(2,h)-1;

        vector<vector<string>> arr(h,vector<string>(c,""));
        filler(root,arr,0,c-1,0);
        return arr;
    }
};
