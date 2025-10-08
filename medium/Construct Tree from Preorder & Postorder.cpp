/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    int i,j;
    Node* helper(vector<int>&a,vector<int>&b)
    {
        Node* root=new Node(a[i]); 
        if(a[i]==b[j])
        {
            j++;
            return root;
        }
        i++;
        root->left=helper(a,b);
        i++;
        root->right=helper(a,b);
        if(root->data==b[j])j++;
        return root;
    }
  
    Node *constructTree(vector<int> &pre, vector<int> &post) 
    {
        i=0;
        j=0;
        return helper(pre,post);
    }
};
