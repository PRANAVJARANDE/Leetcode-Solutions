class Codec {
public:

    void helperrr(TreeNode* root,string &s)
    {
        if(root==NULL)
        {
            s=s+"N,";
            return;
        }
        s+=to_string(root->val)+",";
        helperrr(root->left,s);
        helperrr(root->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string s="";
        helperrr(root,s);
        return s;
    }

    TreeNode* helper(queue<string> &q1)
    {
        string k=q1.front();
        q1.pop();
        if(k=="N")
            return NULL;
        
        
        TreeNode* root=new TreeNode(stoi(k));
        root->left=helper(q1);
        root->right=helper(q1);
        return root;
    }



    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        queue<string> q1;
        string b="";
        for(char x: data)
        {
            if(x==',')
            {
                q1.push(b);
                b="";
            }
            else
            {
                b+=x;
            }
        }
       
        return helper(q1);
    }
};
