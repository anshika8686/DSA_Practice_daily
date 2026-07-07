/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        helper(root,s);
        return s; 
    }
    void helper(TreeNode* root,string &s)
    {
        if(root==nullptr){
            s+="null,";
            return;
        }
        s+=to_string(root->val)+",";

        helper(root->left,s);
        helper(root->right,s);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
         
    }

    TreeNode* buildTree(stringstream &ss){
        string str;
        getline(ss,str,',');

        if(str=="null")
        return nullptr;

        TreeNode* root=new TreeNode(stoi(str));
        root->left=buildTree(ss);
        root->right=buildTree(ss);

        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));