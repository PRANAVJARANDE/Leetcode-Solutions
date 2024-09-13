/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void helper(Node* root,vector<int> &v1)
    {
        if(root==NULL)
        {
            return;
        }
        for(auto x: root->children)
        {
            helper(x,v1);
        }
        v1.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> v1;
        helper(root,v1);
        return v1;
    }
};
