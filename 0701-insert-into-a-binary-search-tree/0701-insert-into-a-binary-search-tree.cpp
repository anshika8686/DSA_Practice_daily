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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        TreeNode* node=new TreeNode(val);
        if(root==nullptr){
            return node;
        }
        TreeNode*prev;
        while(curr!=nullptr){
            if(curr->val<val){
                prev=curr;
                curr=curr->right;
                if(curr==nullptr){
                    prev->right=node;
                }
            }
            else{
                prev=curr;
                curr=curr->left;
                if(curr==nullptr){
                    prev->left=node;
                }
            }
        }
        return root; 
    }
};