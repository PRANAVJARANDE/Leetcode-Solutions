/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    priority_queue<pair<int,int>>q1;
    void helper(Node* root,int t,int k)
    {
        if(!root)return;
        q1.push({abs(root->data - t),root->data});
        if(q1.size()>k)q1.pop();
        helper(root->left,t,k);
        helper(root->right,t,k);
    }
  
  
    vector<int> getKClosest(Node* root, int target, int k) 
    {
        helper(root,target,k);
        vector<int>ans;
        while(!q1.empty())
        {
            ans.push_back(q1.top().second);
            q1.pop();
        }
        return ans;
        
    }
};
