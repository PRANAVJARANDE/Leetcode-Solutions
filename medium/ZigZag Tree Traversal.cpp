/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) 
    {
        vector<int>ans;
        deque<Node*>q1;
        q1.push_back(root);
        int turn=0;
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                if(turn==0)
                {
                    auto node=q1.front();
                    q1.pop_front();
                    ans.push_back(node->data);
                    if(node->left)q1.push_back(node->left);
                    if(node->right)q1.push_back(node->right);    
                }
                else
                {
                    auto node=q1.back();
                    q1.pop_back();
                    ans.push_back(node->data);
                    if(node->right)q1.push_front(node->right); 
                    if(node->left)q1.push_front(node->left);
                }
            }
            turn=1-turn;
        }    
        return ans;
    }
};
