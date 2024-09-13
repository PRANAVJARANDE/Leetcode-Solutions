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
class CBTInserter {
public:

    queue<TreeNode*> q1;
    TreeNode* root;

    CBTInserter(TreeNode* r) {
        root=r;
        q1.push(root);
        while(!q1.empty())
        {
            auto k=q1.front();
            if(k->left && k->right)
            {
                q1.push(k->left);
                q1.push(k->right);
                q1.pop();
            }
            else
            {
                break;
            }
        }
    }
    
    int insert(int val) {
        
        TreeNode* k=q1.front();
        if(k->left==NULL)
        {
            k->left=new TreeNode(val);
            return k->val;
        }
        else if(k->right==NULL)
        {
            k->right=new TreeNode(val);
            return k->val;
        }
        q1.pop();
        q1.push(k->left);
        q1.push(k->right);
        return insert(val);
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
