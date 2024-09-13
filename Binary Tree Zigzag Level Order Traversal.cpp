class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);

        

        vector<int> v1;
        bool b=1;
        while(!q1.empty())
        {
            TreeNode* k=q1.front();
            q1.pop();

            if(k!=NULL)
            {
                v1.push_back(k->val);
                if(k->left!=NULL)
                {
                    q1.push(k->left);
                }
                if(k->right!=NULL)
                {
                    q1.push(k->right);
                }
            }
            else
            {
                

                if(b==1)
                {
                    b=0;
                    ans.push_back(v1);
                }
                else
                {
                    b=1;
                    for(int i=0;i<v1.size()/2;i++)
                    {
                        swap(v1[i],v1[v1.size()-i-1]);
                    }
                    ans.push_back(v1);
                }
                v1.resize(0);
                if(q1.empty())
                {
                    break;
                }
                q1.push(NULL);
            }
        }


    return ans;
        
    }
};
