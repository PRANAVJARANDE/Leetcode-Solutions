class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<Node*> q1;
        q1.push(root);
        q1.push(NULL);

        vector<int> v1;
        while(!q1.empty())
        {
            auto k=q1.front();
            q1.pop();
            if(k!=NULL)
            {
                vector<Node*> child=k->children;
                v1.push_back(k->val);
                for(auto x: child)
                {
                    if(x!=NULL)
                    {
                        q1.push(x);
                    }
                }
            }
            else if(!q1.empty())
            {
                ans.push_back(v1);
                v1.resize(0);
                q1.push(NULL);
            }
            
        }
        ans.push_back(v1);
        return ans;
        
    }
};
