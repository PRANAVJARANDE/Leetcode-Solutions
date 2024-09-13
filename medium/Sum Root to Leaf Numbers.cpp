class Solution {
public:

    void getpath(TreeNode* root,vector<vector<int>> &ans,vector<int> &v1)
    {
        if(root==NULL)
        {
            return ;
        }

        v1.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(v1);
            v1.pop_back();
            return;
        }
        getpath(root->left,ans,v1);
        getpath(root->right,ans,v1);
        v1.pop_back();
    }



    int sumNumbers(TreeNode* root) 
    {
        vector<vector<int>> ans;
        vector<int> v1;

        getpath(root,ans,v1);

        int s=0;
        for(int i=0;i<ans.size();i++)
        {
            string str="";
            for(int j=0;j<ans[i].size();j++)
            {
                char ch=ans[i][j]+'0';
                str=str+ch;
            }
            int u=stoi(str);
            s=s+u;
        }
        return s;


    }
};
