class Solution {
public:

void getnod(TreeNode* root , priority_queue<int,vector<int>,greater<int>> &v1)
{
    if(root==NULL)
    {
        return;
    }
    getnod(root->left,v1);
    v1.push(root->val);
    getnod(root->right,v1);
}


    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        priority_queue<int,vector<int>,greater<int>> v1;
        getnod(root1,v1);
        getnod(root2,v1);

        vector<int> q1;
        while(!v1.empty())
        {
            q1.push_back(v1.top());
            v1.pop();
        }
        return q1;
        
    }
};
