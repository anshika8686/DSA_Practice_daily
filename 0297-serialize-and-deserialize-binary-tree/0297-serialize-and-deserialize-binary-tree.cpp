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
        queue<TreeNode*>q;
        string str;
        if(!root) return "";
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
           
            if(node!=nullptr){
                str.append(to_string(node->val)+",");
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                str.append("null,");
            }
        }
        return str; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*>q;
        if(data.size()==0)
        return nullptr;

        stringstream ss(data);
        string str;
        getline(ss,str,','); //accessed root

        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            getline(ss,str,',');
            if(str=="null"){
                node->left=nullptr;
            }
            else{
            TreeNode* currNode=new TreeNode(stoi(str));
            node->left=currNode;
            q.push(currNode);
            }

            getline(ss,str,',');
            if(str=="null"){
                node->right=nullptr;
            }
            else{
            TreeNode* currNode=new TreeNode(stoi(str));
            node->right=currNode;
            q.push(currNode);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));