/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) 
    {
        map<int,int>m;
        queue<pair<int,Node*>>q1;
        q1.push({0,root});
        while(!q1.empty())
        {
            auto v=q1.front().first;
            auto in=q1.front().second;
            q1.pop();
            m[v]=in->data;
            if(in->left)q1.push({v-1,in->left});
            if(in->right)q1.push({v+1,in->right});
        }
        vector<int>v1;
        for(auto x:m)v1.push_back(x.second);
        return v1;
    }
};
